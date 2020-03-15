#include "Vector.h"

template <typename T>
class Stack: public Vector<T> {
public:
    void push(const T &e) { this->insert(e); }
    T pop() {return this->remove(this->_size - 1); }
    T &top() { return (*this)[this->_size - 1]; }
};
