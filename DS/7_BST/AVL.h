#pragma once
#include "BST.h"
#include "BinNode_macro.h"

template<typename T>
class AVL : public BST<T> {
public:
    BinNodePosi<T> insert(const T &e);
    bool remove(const T &e);
};

template<typename T>
BinNodePosi<T> AVL<T>::insert(const T &e) {
    BinNodePosi<T> &x = search(e);
    if (x)
        return x;
    x = new BinNode<T>(e, this->_hot);
    ++this->_size;
    BinNodePosi<T> xx = x;
    for (BinNodePosi<T> g = this->_hot; g; g = g->parent) {
        if (!AvlBalanced(*g)) {
            FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
            break;
        } else {
            this->updateHeight(g);
        }
    }
    return xx;
}

template<typename T>
bool AVL<T>::remove(const T &e) {
    BinNodePosi<T> &x = search(e);
    if (!x)
        return false;
    this->removeAt(x, this->_hot);
    for (BinNodePosi<T> g = this->_hot; g; g = g->parent) {
        if (!AvlBalanced(*g))
            g = FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
        this->updateHeight(g);
    }
    return true;
}
