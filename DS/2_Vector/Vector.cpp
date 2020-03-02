#include "Vector.h"

/******************内部函数*********************/
template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {
// void Vector::copyFrom(T const* A, Rank lo, Rank hi) {
    // 假设_elem指向的原内存已经释放
    _size = hi - lo;
    _capacity = 2 * _size;
    _elem = new T[_capacity];
    for (auto i = 0; i != _size; ++i) {
        _elem[i] = A[lo + i];
    }
}

template <typename T>
void Vector<T>::expand() {
// void Vector::expand() {
    if (_size < _capacity)
        return;
    if (_capacity < DEFAULT_CAPACITY)
        _capacity = DEFAULT_CAPACITY;
    auto new_elem = new T[_capacity * 2];
    for (auto i = 0; i != _size; ++i) 
        new_elem[i] = _elem[i];
    delete [] _elem;
    _elem = new_elem;
    _capacity *= 2;
}


template <typename T>
void Vector<T>::shrink() {
// void Vector::shrink() {
    if (_capacity < 4 * _size || _capacity < 2 * DEFAULT_CAPACITY)
        return;
    
    auto new_elem = new T[_capacity / 2];
    for (auto i = 0; i != _size; ++i) {
        new_elem[i] = _elem[i];
    }
    delete [] _elem;
    _elem = new_elem;
    _capacity /= 2;
}

/******************只读访问接口*********************/
// template <typename T>
// int Vector<T>::disordered() const {
// int Vector::disordered() const {

// }

// template <typename T>
// Rank Vector<T>::find(const T& e, Rank lo, Rank hi) const {
// Rank Vector::find(const T& e, Rank lo, Rank hi) const {

// }

// template <typename T>
// Rank Vector<T>::search(const T& e, Rank lo, Rank hi) const { // 有序
// Rank Vector::search(const T& e, Rank lo, Rank hi) const {

// }

/******************可写访问接口*********************/
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rv) {
// Vector& Vector::operator=(const Vector& rv) {
    delete [] _elem;
    copyFrom(rv._elem, 0, rv._size);
    return *this;
}

template <typename T>
Rank Vector<T>::insert(Rank r, const T& e) {
// Rank Vector::insert(Rank r, const T& e) {
    expand();
    for (auto i = _size; i > r; --i) {
        _elem[i] = _elem[i - 1];
    }
    _elem[r] = e;
    ++_size;
    return r;
}

template <typename T>
T Vector<T>::remove(Rank r) {
// T Vector::remove(Rank r) {
    T tmp = _elem[r];
    remove(r, r + 1);
    return tmp;
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
// int Vector::remove(Rank lo, Rank hi) {
    if (lo == hi)
        return 0;
    for (auto i = 0; i != _size - hi; ++i) {
        _elem[lo + i] = _elem[hi + i];
    }
    _size -= hi - lo;
    shrink();
    return hi - lo;
}

// template <typename T>
// void Vector<T>::deduplicate() {
// void Vector::deduplicate() {

// }

// template <typename T>
// void Vector<T>::uniquify() {
// void Vector::uniquify() {

// }
