using Pos = int;
constexpr int nullpos = -1;

template <typename T>
class List {
    friend void read(List<char>& l);
private:
    Pos *_prev; // 两个哨兵节点，n + 2
    Pos *_succ; // 两个哨兵节点，n + 2
    T *_elem;   // 两个哨兵节点，n + 2
    Pos data;
    Pos free;
    Pos header;
    Pos trailer;
    int _n;
    int _size;
    // 私有函数
    void init();

public:
    // 构造和析构
    List(int n) : data(nullpos), free(0), header(n), trailer(n + 1), _n(n), _size(0) { init(); } // inline
    ~List() { delete[] _prev; delete[] _succ; delete[] _elem; } // inline

    // 只读函数
    int size() const { return _size; } // inline
    bool empty() const { return _size <= 0; } // inline
    bool valid(Pos p) const { return p >= 0 && p < _n; } // inline
    Pos prev(Pos p) const { return _prev[p]; } // inline
    Pos succ(Pos p) const { return _succ[p]; } // inline
    Pos elem(Pos p) const { return _elem[p]; }
    Pos first() const { return _succ[header]; } // inline
    Pos last() const { return _prev[trailer]; } // inline
    void reverse() { reverse(first(), trailer); }
    void reverse(Pos pl, Pos pr);

    // 可写函数
    Pos insertAsFirst(const T &e) { ++_size; return insertA(header, e); }
    Pos insertAsLast(const T &e) { ++_size; return insertB(trailer, e); }
    Pos insertA(Pos p, const T &e);
    Pos insertB(Pos p, const T &e);
    T remove(Pos p);
};

template <typename T> void List<T>::init() {
    _prev = new Pos[_n + 2];
    _succ = new Pos[_n + 2];
    _elem = new T[_n + 2]; // 也可以是_n
    // 默认初始化节点
    for (int i = 0; i != _n; ++i) {
        _prev[i] = nullpos;
        if (i != _n - 1 ) {
            _succ[i] = i + 1;
        } else {
            _succ[i] = nullpos;
        }
    }
    // 初始化哨兵节点
    _prev[header] = nullpos;
    _succ[header] = trailer;
    _prev[trailer] = header;
    _succ[trailer] = nullpos;
}

template <typename T> Pos List<T>::insertA(Pos p, const T &e) {
    ++_size;
    // new一个内存
    data = free;
    free = _succ[free];
    // 初始化
    _elem[data] = e;
    _prev[data] = p;
    _succ[data] = _succ[p]; // p不能是trailer
    // 调整前后元素的指针
    _prev[_succ[p]] = data; // p不能是trailer
    _succ[p] = data;
    return data;
}

template <typename T> Pos List<T>::insertB(Pos p, const T &e) {
    ++_size;
    // new一个内存
    data = free;
    free = _succ[free];
    // 初始化
    _elem[data] = e;
    _succ[data] = p;
    _prev[data] = _prev[p]; // p不能是header
    // 调整前后元素的指针
    _succ[_prev[p]] = data; // p不能是header
    _prev[p] = data;
    return data;
}

template <typename T> T List<T>::remove(Pos p) {
    // 调整前后元素指针
    _succ[_prev[p]] = _succ[p];
    _prev[_succ[p]] = _prev[p];
    // 释放内存
    _prev[p] = nullpos;
    _succ[p] = free;
    free = p;
    --_size;
    return _elem[p];
}

template <typename T> void swap(T& a, T& b) {
    T tmp = b;
    b = a;
    a = tmp;
}

template <typename T> void List<T>::reverse(Pos pl, Pos pr) {
    while (pl != pr && _prev[pl] != pr) {
        swap(_elem[pl], _elem[pr]);
        pl = _succ[pl];
        pr = _prev[pr];
    }
}
