#include "ListNode.h"

template <typename T>
class List {
private:
    Rank _size;
    Posi<T> header;
    Posi<T> trailer;

protected:
    void init(); // 初始化
    int clear(); // 清除所有单元
    void copyNodes(Posi<T> p, int n); // 复制
    void selectionSort(Posi<T> p, int n); // 选择排序
    void insertionSort(Posi<T> p, int n); // 插入排序
    void mergeSort(Posi<T>& p, int n);

public:
    // 构造函数
    List() { init(); } // inline
    List(const List<T> &l);
    List(const List<T> &l, Rank r, int n);
    List(Posi<T> p, int n);
    // 析构函数
    ~List();
    // 只读接口
    Rank size() const { return _size; } // inline
    bool empty() const { return _size <= 0; } // inline
    T &operator[](Rank r) const;
    Posi<T> first() const { return header->succ; } // inline
    Posi<T> last() const { return trailer->pred; } // inline
    bool valid(Posi<T> p) const { return p && p != header && p != trailer; } // inline
    int disordered() const;
    Posi<T> find(const T &e) { return find(e, _size, trailer); } // inline
    Posi<T> find(const T &e, Rank n, Posi<T> p) const; // 无序查找
    Posi<T> search(const T &e) const { return search(e, _size, trailer); } // inline
    Posi<T> search(const T &e, Rank n, Posi<T> p) const; // 有序查找
    Posi<T> searchMax() const { return searchMax(header, _size); } // inline
    Posi<T> searchMax(Posi<T> p, Rank n) const;
    // 可写接口
    Posi<T> insertAsFirst(const T &e);
    Posi<T> insertAsLast(const T &e);
    Posi<T> insertA(Posi<T> p, const T &e);
    Posi<T> insertB(Posi<T> p, const T &e);
    T remove(Posi<T> p);
    void merge(Posi<T>& p, Rank n, List<T>& l, Posi<T> q, Rank m);
    void sort() { sort(first(), _size); } // inline
    void sort(Posi<T> p, int n);
    int deduplicate(); // 无序去重
    int uniquify(); // 有序去重
    void reverse();
    // 遍历
    void traverse(void (*visit)(const T &e));
    template <typename VST> void traverse(VST &visit);  
};

/*******************内部函数**********************/
template <typename T> void List<T>::init() {
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pred = nullptr;
    trailer->pred = header;
    trailer->succ = nullptr;
    _size = 0;
}

template <typename T> int List<T>::clear() {
    Rank old_size = _size;
    while (_size > 0) {
        remove(header->succ);
    }
    return old_size;
}

template <typename T> void List<T>::copyNodes(Posi<T> p, int n) {
    init();
    for (Rank i = 0; i != n; ++i) {
        insertAsLast(p->data);
        p = p->succ;
    }
}

template<typename T> void List<T>::selectionSort(Posi<T> p, int n) {
    Posi<T> last = p;
    for (Rank i = 0; i < n - 1; ++i) {
        last = last->succ;
    }
    for (Rank i = n; i > 1; last = last->pred, --i) {
        Posi<T> q = searchMax(p, i);
        if (q != last) {
            T tmp = q->data;
            q->data = last->data;
            last->data = tmp;
        }
    }
}

template<typename T> void List<T>::insertionSort(Posi<T> p, int n) {
    for (Rank i = 0; i != n; ++i) {
        Posi<T> q = search(p->data, i, p);
        insertA(q, p->data);
        p = p->succ;
        remove(p->pred);
    }
}

template<typename T> void List<T>::mergeSort(Posi<T>& p, int n) {
    if (n < 2)
        return;
    Rank m = n / 2;
    Posi<T> q = p;
    for (Rank i = 0; i != m; ++i) {
        q = q->succ;
    }
    mergeSort(p, m);
    mergeSort(q, n - m);
    merge(p, m, *this, q, n - m);
}

/******************构造与析构函数*******************/
template <typename T> List<T>::List(const List<T> &l) {
    copyNodes(l.first(), l._size);
}

template <typename T> List<T>::List(const List<T> &l, Rank r, int n) {
    Posi<T> p = l.first();
    for (Rank i = 0; i != r; ++i) {
        p = p->succ;
    }
    copyNodes(p, n);
}

template <typename T> List<T>::List(Posi<T> p, int n) {
    copyNodes(p, n);
}

template <typename T> List<T>::~List() {
    clear();
    delete header;
    delete trailer;
}

/*******************只读函数*********************/
template <typename T> T& List<T>::operator[](Rank r) const {
    Posi<T> p = first();
    for (Rank i = 0; i != r; ++i) {
        p = p->succ;
    }
    return p->data;
}

// template <typename T> int List<T>::disordered() const {

// }

template <typename T> Posi<T> List<T>::find(const T &e, Rank n, Posi<T> p) const {
    for (p = p->pred; n > 0; --n) {
        if (p->data == e)
            return p;
        p = p->pred;
    }
    return nullptr;
}

template <typename T> Posi<T> List<T>::search(const T &e, Rank n, Posi<T> p) const { // 有序查找
    for (p = p->pred; n > 0; --n) {
        if (p->data <= e)
            return p;
        p = p->pred;
    }
    return p;
}

template <typename T> Posi<T> List<T>::searchMax(Posi<T> p, Rank n) const {
    Posi<T> p_max = p;
    for (Rank i = 0; i != n; ++i) {
        if (p->data >= p_max->data)
            p_max = p;
        p = p->succ;
    }
    return p_max;
}

/*******************可写函数*********************/
template <typename T> Posi<T> List<T>::insertAsFirst(const T &e) {
    ++_size;
    return header->insertAsSucc(e);
}

template <typename T> Posi<T> List<T>::insertAsLast(const T &e) {
    ++_size;
    return trailer->insertAsPred(e);
}

template <typename T> Posi<T> List<T>::insertA(Posi<T> p, const T &e) {
    ++_size;
    return p->insertAsSucc(e);
}

template <typename T> Posi<T> List<T>::insertB(Posi<T> p, const T &e) {
    ++_size;
    return p->insertAsPred(e);
}

template <typename T> T List<T>::remove(Posi<T> p) {
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    --_size;
    return e;
}

template<typename T> void List<T>::merge(Posi<T>& p, Rank n, List<T>& l, Posi<T> q, Rank m) {
    Posi<T> pp = p->pred;
    while (m > 0) {
        if (n > 0 && p->data <= q->data) {
            p = p->succ;
            if (p == q)
                break;
            --n;
        } else {
            q = q->succ;
            insertB(p, l.remove(q->pred));
            --m;
        }
    }
    p = pp->succ;
}

// template<typename T> void List<T>::merge(Posi<T>& p, Rank n, List<T>& l, Posi<T> q, Rank m) {
//     Posi<T> pp = p->pred;
//     for (Rank i = 0, j = 0; i < n || j < m; ) {
//         if (i < n && (j >= m || p->data <= q->data)) {
//             p = p->succ;
//             ++i;
//         }
//         if (j < m && (i >= n || q->data < p->data)) {
//             q = q->succ;
//             insertB(p, l.remove(q->pred));
//             ++j;
//         }
//     }
//     p = pp->succ;
// }

template<typename T> void List<T>::sort(Posi<T> p, int n) {
    // insertionSort(p, n);
    // selectionSort(p, n);
    mergeSort(p, n);
}

template<typename T> int List<T>::deduplicate() { // 无序去重
    Rank old_size = _size;
    Posi<T> p=first();
    for (Rank i = 0; p != trailer; p = p->succ) {
        Posi<T> q = find(p->data, i, p);
        if (q)
            remove(q);
        else
            ++i;
    }
    return old_size - _size;
}

template<typename T> int List<T>::uniquify() { // 有序去重
    Rank old_size = _size;
    for (Posi<T> p = first(), q = p->succ; p != trailer; q = p->succ) {
        if (q->data == p->data) {
            remove(q);
        } else {
            p = q;
        }
    }
    return old_size - _size;
}

/*********************遍历*************************/
template<typename T> void List<T>::traverse(void (*visit)(const T &e)) {
    for (Posi<T> p=header->succ; p != trailer; p = p->succ) {
        visit(p->data);
    }
}

template<typename T> template <typename VST> void List<T>::traverse(VST &visit) {
    for (Posi<T> p=header->succ; p != trailer; p = p->succ) {
        visit(p->data);
    }
}
