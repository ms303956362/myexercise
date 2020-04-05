#pragma once
#include "BinNode.h"
#include "release.h"

template <typename T>
class BinTree {
protected:
    int _size;
    BinNodePosi<T> _root;
    virtual int updateHeight(BinNodePosi<T> x);
    void updateHeightAbove(BinNodePosi<T> x);
    int removeAt(BinNodePosi<T> x);

public:
    // 构造和析构函数
    BinTree() : _size(0), _root(nullptr){};  // inline
    virtual ~BinTree(){ if (_size > 0) remove(_root); }  // inline
    // 只读函数
    int size() const { return _size; }  // inline
    bool empty() const { return !_root; }  // inline
    BinNodePosi<T> root() const { return _root; }  // inline
    // 读写函数
    BinNodePosi<T> insertAsRoot(const T &e);
    BinNodePosi<T> insertAsLC(BinNodePosi<T> x, const T &e);
    BinNodePosi<T> insertAsRC(BinNodePosi<T> x, const T &e);
    BinNodePosi<T> attachAsLC(BinNodePosi<T> x, BinTree<T>*& st);
    BinNodePosi<T> attachAsRC(BinNodePosi<T> x, BinTree<T>*& st);
    int remove(BinNodePosi<T> x);
    BinTree<T> *secede(BinNodePosi<T> x); // 删除子树x后作为独立的树返回
    template <typename VST>
    void travPre(VST& visit) { if (_root) _root->travPre(visit);}
    template <typename VST>
    void travIn(VST& visit) { if (_root) _root->travIn(visit);}
    template <typename VST>
    void travPost(VST& visit) { if (_root) _root->travPost(visit);}
    template <typename VST>
    void travLevel(VST& visit) { if (_root) _root->travLevel(visit);}
};


/***********************私有函数*************************/
template <typename T>
int BinTree<T>::updateHeight(BinNodePosi<T> x) {
    int lh = -1, rh = -1;
    if (x->lc)
        lh = x->lc->height;
    if (x->rc)
        rh = x->rc->height;
    x->height = (lh > rh ? lh : rh) + 1;
    return x->height;
}

template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi<T> x) {
    if (x) {
        int old_height = x->height;
        while (x && old_height != updateHeight(x)) {
            x = x->parent;
            if (x)
                old_height = x->height;
        }
    }
}

template <typename T>
int BinTree<T>::removeAt(BinNodePosi<T> x) {
    if (!x)
        return 0;
    int n = 1 + removeAt(x->lc) + removeAt(x->rc);
    release(x->data);
    release(x);
    return n;
}

/***********************读写函数************************/
template <typename T>
BinNodePosi<T> BinTree<T>::insertAsRoot(const T &e) {
    _size = 1;
    _root = new BinNode<T>(e);
    return _root;
}

template <typename T>
BinNodePosi<T> BinTree<T>::insertAsLC(BinNodePosi<T> x, const T &e) {
    ++_size;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}

template <typename T>
BinNodePosi<T> BinTree<T>::insertAsRC(BinNodePosi<T> x, const T &e) {
    ++_size;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}

template <typename T>
BinNodePosi<T> BinTree<T>::attachAsLC(BinNodePosi<T> x, BinTree<T>*& st) {
    x->lc = st->_root;
    if (x->lc)
        x->lc->parent = x;
    _size += st->_size;
    updateHeightAbove(x);
    // 释放st，注意_root要先指向别处，否则_root指向的内存被释放
    st->_root = nullptr;
    st->_size = 0;
    release(st);
    st = nullptr;
    return x;
}

template <typename T>
BinNodePosi<T> BinTree<T>::attachAsRC(BinNodePosi<T> x, BinTree<T>*& st) {
    x->rc = st->_root;
    if (x->rc)
        x->rc->parent = x;
    _size += st->_size;
    updateHeightAbove(x);
    st->_root = nullptr;
    st->_size = 0;
    release(st);
    st = nullptr;
    return x;
}

template <typename T>
int BinTree<T>::remove(BinNodePosi<T> x) {
    if (x->parent) {
        BinNodePosi<T>& fromParentToMe = (x->parent->lc == x ? x->parent->lc : x->parent->rc);
        fromParentToMe = nullptr;
        updateHeightAbove(x->parent);
    }
    int n = removeAt(x);
    _size -= n;
    return n;
}

template <typename T>
BinTree<T>* BinTree<T>::secede(BinNodePosi<T> x) {
    // 创建新树
    BinTree<T> *st = new BinTree<T>;
    st->_size = x->size();
    st->_root = x;
    // 切断与原树联系
    if (x->parent) {
        BinNodePosi<T>& fromParentToMe = (x->parent->lc == x ? x->parent->lc : x->parent->rc);
        fromParentToMe = nullptr;
        updateHeightAbove(x->parent);
    }
    x->parent = nullptr;
    _size -= st->_size;
    return st;
}
