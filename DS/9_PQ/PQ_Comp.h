#include "Vector.h"
#include "PQ.h"

/**************************宏**************************/
inline Rank Parent(Rank i) { return (i - 1) >> 1; }
inline Rank LChild(Rank i) { return 1 + (i << 1); }
inline Rank RChild(Rank i) { return (1 + i) << 1; }

/**********************通用算法************************/
template <typename T>
Rank percolateDown(T *A, Rank n, Rank i) {
    while (i < n) {
        Rank lc = LChild(i), rc = RChild(i), j = i;
        if (lc < n && A[j] < A[lc])
            j = lc;
        if (rc < n && A[j] < A[rc])
            j = rc;
        if (j == i)
            break;
        swap1(A[i], A[j]);
        i = j;
    }
    return i;
}

template <typename T>
Rank percolateUp(T *A, Rank i) {
    while (0 < i) {
        Rank j = Parent(i);
        if (A[i] < A[j])
            break;
        swap1(A[i], A[j]);
        i = j;
    }
    return i;
}

template <typename T>
void heapify(T* A, Rank n) {
    for (Rank i = n / 2 - 1; i >= 0; --i) {
        percolateDown(A, n, i);
    }
}

/************************模板类************************/
template <typename T> struct PQ_Comp : public PQ<T>, public Vector<T> {
    PQ_Comp(T* A, int n) {
        this->copyFrom(A, 0, n);
        heapify(A, n);
    }
    void insert(T e);
    T& getMax() { return this->_elem[0]; } // inline
    T delMax();
};

/**********************成员函数***********************/
template <typename T>
void PQ_Comp<T>::insert(T e) {
    Vector<T>::insert(e);
    percolateUp(this->_elem, this->_size - 1);
}

template <typename T>
T PQ_Comp<T>::delMax() {
    T tmp = this->_elem[0];
    this->_elem[0] = this->_elem[--this->_size];
    percolateDown(this->_elem, this->_size, 0);
    return tmp;
}
