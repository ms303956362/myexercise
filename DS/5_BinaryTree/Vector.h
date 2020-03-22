#include "search.h"
#include "sort.h"

using Rank = int;
constexpr int DEFAULT_CAPACITY = 3;

template <typename T>
class Vector {
protected:
    // 内部变量
    Rank _size;
    Rank _capacity;
    T* _elem;
    // 内部函数
    void copyFrom(T const* A, Rank lo, Rank hi);
    void expand();
    void shrink();

public:
    // 构造函数
    Vector(Rank size = 0, const T& v = T(), Rank capacity = DEFAULT_CAPACITY) 
        : _size(size), _capacity(size > capacity ? size : capacity) 
    { _elem = new T[_capacity]; for (Rank i=0; i!=size; ++i) _elem[i] = v; } // inline
    Vector(T const * A, Rank n) { copyFrom(A, 0, n); } // inline
    Vector(T const * A, Rank lo, Rank hi) { copyFrom(A, lo, hi); } // inline
    Vector(const Vector<T>& v) { copyFrom(v._elem, 0, v._size); } // inline
    Vector(const Vector<T>& v, Rank lo, Rank hi) { copyFrom(v._elem, lo, hi); } // inline
    
    // 析构函数
    ~Vector() { delete [] _elem; } // inline
    
    // 只读访问函数
    Rank size() const { return _size;} // inline
    bool empty() const { return static_cast<bool>(!_size); } // inline
    const T& operator[] (Rank r) const { return _elem[r]; } // inline, 默认满足0 <= r < _size，否则属于未定义行为
    int disordered() const;
    Rank find(const T& e) const { return find(e, 0, _size); } // inline
    Rank find(const T& e, Rank lo, Rank hi) const;
    Rank search(const T& e) const { return _size <= 0 ? -1 : search(e, 0, _size); } // 有序，inline
    Rank search(const T& e, Rank lo, Rank hi) const; // 有序
    
    // 可写访问接口
    Vector<T>& operator=(const Vector<T>& rv);
    T& operator[](Rank r) { return _elem[r]; } // inline, 默认满足0 <= r < _size，否则属于未定义行为
    Rank insert(Rank r, const T& e);
    Rank insert(const T& e) { return insert(_size, e); } // inline
    T remove(Rank r);
    int remove(Rank lo, Rank hi);
    void sort() { sort(0, _size); } // inline
    void sort(Rank lo, Rank hi);
    int deduplicate();
    int uniquify();

    // 遍历
    void traverse(void (*)(T& ));
    template <typename VST> void traverse(VST&);
};

/**************************************************************************************/
/*************************************方便调试*****************************************/
/**************************************************************************************/

/******************内部函数*********************/
template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {
    // 假设_elem指向的原内存已经释放
    _size = hi - lo;
    _capacity = 2 * _size;
    _elem = new T[_capacity];
    for (Rank i = 0; i != _size; ++i) {
        _elem[i] = A[lo + i];
    }
}

template <typename T>
void Vector<T>::expand() {
    if (_size < _capacity)
        return;
    if (_capacity < DEFAULT_CAPACITY)
        _capacity = DEFAULT_CAPACITY;
    auto new_elem = new T[_capacity * 2];
    for (Rank i = 0; i != _size; ++i) 
        new_elem[i] = _elem[i];
    delete [] _elem;
    _elem = new_elem;
    _capacity *= 2;
}


template <typename T>
void Vector<T>::shrink() {
    if (_capacity < 4 * _size || _capacity < 2 * DEFAULT_CAPACITY)
        return;
    
    auto new_elem = new T[_capacity / 2];
    for (Rank i = 0; i != _size; ++i) {
        new_elem[i] = _elem[i];
    }
    delete [] _elem;
    _elem = new_elem;
    _capacity /= 2;
}

/******************只读访问接口*********************/
template <typename T>
int Vector<T>::disordered() const {
    int cnt = 0;
    for (Rank i = 0; i != _size - 1; ++i) {
        if (_elem[i] > _elem[i + 1])
            ++cnt;
    }
    return cnt;
}

template <typename T>
Rank Vector<T>::find(const T& e, Rank lo, Rank hi) const {
    Rank i = hi - 1; 
    while (i >= lo && _elem[i] != e) 
        --i;
    return i; // i < lo表示未找到
}

template <typename T>
Rank Vector<T>::search(const T& e, Rank lo, Rank hi) const { // 有序
    // return fibSearch(_elem, e, lo, hi);
    return binarySearch(_elem, e, lo, hi);
}

/******************可写访问接口*********************/
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rv) {
    delete [] _elem;
    copyFrom(rv._elem, 0, rv._size);
    return *this;
}

template <typename T>
Rank Vector<T>::insert(Rank r, const T& e) {
    expand();
    for (Rank i = _size; i > r; --i) {
        _elem[i] = _elem[i - 1];
    }
    _elem[r] = e;
    ++_size;
    return r;
}

template <typename T>
T Vector<T>::remove(Rank r) {
    T tmp = _elem[r];
    remove(r, r + 1);
    return tmp;
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
    if (lo == hi)
        return 0;
    for (Rank i = 0; i != _size - hi; ++i) {
        _elem[lo + i] = _elem[hi + i];
    }
    _size -= hi - lo;
    shrink();
    return hi - lo;
}

template <typename T>
void Vector<T>::sort(Rank lo, Rank hi) {
    // bubbleSort(_elem, lo, hi);
    mergeSort(_elem, lo, hi);
}

template <typename T>
int Vector<T>::deduplicate() {
    auto old_size = _size;
    for (Rank i = 0; i != _size; ) {
        if (find(_elem[i], 0, i) != -1)
            remove(i);
        else
            ++i;
    }
    return old_size - _size;
}

template <typename T>
int Vector<T>::uniquify() {
    Rank new_end = 0;
    Rank i = 1;
    for (; i != _size; ++i) {
        if (_elem[i] != _elem[new_end]) {
            _elem[++new_end] = _elem[i];
        }
    }
    _size = ++new_end;
    shrink();
    return i - new_end;
}

/**********************遍历*************************/
template <typename T>
void Vector<T>::traverse(void (*visit)(T& )) {
    for (Rank i=0; i != _size; ++i) {
        visit(_elem[i]);
    }
}

template <typename T> template <typename VST>
void Vector<T>::traverse(VST& visit) {
    for (Rank i=0; i != _size; ++i) {
        visit(_elem[i]);
    }
}
