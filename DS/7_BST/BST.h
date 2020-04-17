#pragma once
#include "BinTree.h"
#include "BinNode_macro.h"

template <typename T>
class BST : public BinTree<T> {
protected:
    BinNodePosi<T> connect34(BinNodePosi<T> a, BinNodePosi<T> b, BinNodePosi<T> c,
                             BinNodePosi<T> T0, BinNodePosi<T> T1, BinNodePosi<T> T2, BinNodePosi<T> T3);
    BinNodePosi<T> rotateAt(BinNodePosi<T> x);  // 确定a,b,c,T0,T1,T2,T3后3+4重构的统一实现

public:
    BinNodePosi<T> _hot; // 搜索命中节点的父节点
    virtual BinNodePosi<T> &search(const T &e);
    virtual BinNodePosi<T> &search1(const T &e);
    virtual BinNodePosi<T> insert(const T &e);
    virtual bool remove(const T &);
};

/**************************私有接口*****************************/
template <typename T>
BinNodePosi<T> BST<T>::connect34(BinNodePosi<T> a, BinNodePosi<T> b, BinNodePosi<T> c,
        BinNodePosi<T> T0, BinNodePosi<T> T1, BinNodePosi<T> T2, BinNodePosi<T> T3) {
    // a
    a->lc = T0;
    if (T0)
        T0->parent = a;
    a->rc = T1;
    if (T1)
        T1->parent = a;
    // c
    c->lc = T2;
    if (T2)
        T2->parent = c;
    c->rc = T3;
    if (T3)
        T3->parent = c;
    // b
    b->lc = a;
    a->parent = b;
    b->rc = c;
    c->parent = b;
    this->updateHeight(a);
    this->updateHeight(c);
    this->updateHeight(b);
    return b;
}

template <typename T>
BinNodePosi<T> BST<T>::rotateAt(BinNodePosi<T> x) {
    BinNodePosi<T> p = x->parent, g = p->parent;
    if (IsLChild(*x)) {
        if (IsLChild(*p)) {
            p->parent = g->parent;
            return connect34(x, p, g, x->lc, x->rc, p->rc, g->rc);
        } else {
            x->parent = g->parent;
            return connect34(g, x, p, g->lc, x->lc, x->rc, p->rc);
        }
    } else {
        if (IsLChild(*p)) {
            x->parent = g->parent;
            return connect34(p, x, g, p->lc, x->lc, x->rc, g->rc);
        } else {
            p->parent = g->parent;
            return connect34(g, p, x, g->lc, p->lc, x->lc, x->rc);
        }
    }
}

/*************************公开接口****************************/
template <typename T>
BinNodePosi<T> &BST<T>::search(const T &e) { // 无论是否成功，_hot为查找元素的父节点，返回值为查找元素的节点
    return searchIn(this->_root, e, _hot = nullptr);
}

template <typename T>
BinNodePosi<T> &BST<T>::search1(const T &e) { // 无论是否成功，_hot为查找元素的父节点，返回值为查找元素的节点
    return searchAll(this->_root, e, _hot = nullptr);
}

template <typename T>
BinNodePosi<T> BST<T>::insert(const T &e) {
    BinNodePosi<T>& x = search(e);
    if (!x) {
        x = new BinNode<T>(e, _hot);
        ++this->_size;
        this->updateHeightAbove(x);
    }
    return x;
}

template <typename T>
bool BST<T>::remove(const T& e) {
    BinNodePosi<T>& x = search(e);
    if (!x) 
        return false;
    removeAt(x, _hot);
    --this->_size;
    this->updateHeightAbove(_hot);
    return true;
}

/*************************静态方法***************************/
template <typename T>
static BinNodePosi<T>& searchIn(BinNodePosi<T>& v, const T& e, BinNodePosi<T>& hot) { // 限定本文件调用
    if (!v || v->data == e) { // 树根
        return v;
    }
    hot = v;
    while (1) {
        BinNodePosi<T>& c = hot->data < e ? hot->rc : hot->lc;
        if (!c || c->data == e)
            return c; // （1）查找成功：c指向查找元素 （2）查找失败：c指向可插入的位置
        hot = c;
    }
}

template <typename T>
static BinNodePosi<T>& searchAll(BinNodePosi<T>& v, const T& e, BinNodePosi<T>& hot) { // 限定本文件调用
    if (!v) { // 树根
        return v;
    }
    hot = v;
    while (1) {
        BinNodePosi<T>& c = hot->data < e ? hot->rc : hot->lc;  // 相等时统一向左
        if (!c)
            return c; // 必为叶节点，有相同元素时为最后一个相同元素的前驱
        hot = c;
    }
}

template <typename T>
static BinNodePosi<T> removeAt(BinNodePosi<T>& x, BinNodePosi<T>& hot) {
    BinNodePosi<T> w = x; // 实际被删除节点
    BinNodePosi<T> succ; // 顶替的节点
    if (!x->lc) { // 没有左子树
        succ = x = x->rc; // x是引用，hot的孩子改为x的孩子
    } else if (!x->rc) { // 没有右子树
        succ = x = x->lc;
    } else { // 二者都有
        w = w->succ(); // w为x中序遍历后继，只可能有右子树
        swap(x->data, w->data);
        succ = w->rc;
        BinNodePosi<T> u = w->parent;
        (u == x ? u->rc : u->lc) = succ = w->rc;
    }
    hot = w->parent;
    if (succ)
        succ->parent = hot;
    release(w->data);
    release(w);
    return succ;
}