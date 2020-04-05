#pragma once
#include "Stack.h"
#include "Queue.h"

template <typename T> class BinNode;

template <typename T>
using BinNodePosi = BinNode<T>*;

enum RBColor { RB_RED, RB_BLACK };

template <typename T>
class BinNode {
    friend bool operator<(const BinNode &lbn, const BinNode &rbn) { return lbn.data < rbn.data; }
    friend bool operator<=(const BinNode &lbn, const BinNode &rbn) { return lbn.data <= rbn.data; }
    friend bool operator>(const BinNode &lbn, const BinNode &rbn) { return lbn.data > rbn.data; }
    friend bool operator>=(const BinNode &lbn, const BinNode &rbn) { return lbn.data >= rbn.data; }
    friend bool operator==(const BinNode &lbn, const BinNode &rbn) { return lbn.data == rbn.data; }
    friend bool operator!=(const BinNode &lbn, const BinNode &rbn) { return lbn.data != rbn.data; }

public:
    BinNodePosi<T> parent; // 父节点
    BinNodePosi<T> lc;     // 左孩子
    BinNodePosi<T> rc;     // 右孩子
    T data;
    int height; // 子树的height
    int npl;
    RBColor color;
    // 构造函数
    BinNode() : parent(nullptr), lc(nullptr), rc(nullptr), height(0), npl(1), color(RB_RED){};
    BinNode(T e, BinNodePosi<T> p = nullptr, BinNodePosi<T> l = nullptr, BinNodePosi<T> r = nullptr, 
            int h = 0, int n = 1, RBColor c = RB_RED) : 
        parent(p), lc(l), rc(r), data(e), height(h), npl(n), color(c){};
    // 只读函数
    int size() const; // 子树的size
    // 读写函数
    BinNodePosi<T> insertAsLC(const T &e); // 作为左孩子节点插入
    BinNodePosi<T> insertAsRC(const T &e); // 作为右孩子节点插入
    BinNodePosi<T> succ(); // 中序遍历时的后继
    template <typename VST>
    void travPre(VST &visit);   // 先序遍历
    template <typename VST>
    void travIn(VST &visit);    // 中序遍历
    template <typename VST>
    void travPost(VST &visit);  // 后序遍历
    template <typename VST>
    void travLevel(VST &visit); // 层次遍历
};

// 只读函数
template <typename T>
int BinNode<T>::size() const {
    int s = 1;
    if (lc)
        s += lc->size();
    if (rc)
        s += rc->size();
    return s;
}

// 读写函数
template <typename T>
BinNodePosi<T> BinNode<T>::insertAsLC(const T &e) {
    return lc = new BinNode(e, this);
}

template <typename T>
BinNodePosi<T> BinNode<T>::insertAsRC(const T &e) {
    return rc = new BinNode(e, this);
}

template <typename T>
BinNodePosi<T> BinNode<T>::succ() {
    BinNodePosi<T> x = this;
    if (rc) {   // 有右子树
        x = rc;
        while (x->lc) { // 右子树左侧链最底
            x = x->lc;
        }
    } else {    // 没右孩子
        while (x->parent != nullptr && x == x->parent->rc) {    // 向左上运动
            x = x->parent;
        }
        x = x->parent;  // 左孩子节点的父亲
    }
    return x;
}

template <typename T> template <typename VST>
void BinNode<T>::travPre(VST &visit) {
    Stack<BinNodePosi<T>> s;
    BinNodePosi<T> x = this;
    while (true) {
        // visitAlongVine
        while (x) {
            visit(x->data);
            if (x->rc)
                s.push(x->rc);
            x = x->lc;
        }
        if (s.empty())
            break;
        x = s.pop();
    }
}

template <typename T> template <typename VST>
void BinNode<T>::travIn(VST &visit) {
    Stack<BinNodePosi<T>> s;
    BinNodePosi<T> x = this;
    while (true) {
        // goAlongVine
        while (x) {
            s.push(x);
            x = x->lc;
        }
        if (s.empty()) {
            break;
        }
        x = s.pop();
        visit(x->data);
        x = x->rc;
    }
}

template <typename T> template <typename VST>
void BinNode<T>::travPost(VST &visit) {
    Stack<BinNodePosi<T>> s;
    BinNodePosi<T> x = this;
    s.push(x);
    while (true) {
        if (s.top() != x->parent) {
            x = s.top();
            while (x) {
                if (s.top() != x) // 栈顶不是x（x->parent->rc），rc上次迭代已入栈
                    s.push(x);
                if (x->rc)
                    s.push(x->rc);
                if (x->lc)  // 能向左则向左
                    x = x->lc;
                else
                    x = x->rc;
            }
        }
        x = s.pop();
        visit(x->data);
        if (s.empty())
            break;
    }
}

template <typename T> template <typename VST>
void BinNode<T>::travLevel(VST &visit) {
    BinNodePosi<T> x = this;
    Queue<BinNodePosi<T>> q;
    q.enqueue(x);
    while (!q.empty()) {
        x = q.dequeue();
        visit(x->data);
        if (x->lc)
            q.enqueue(x->lc);
        if (x->rc)
            q.enqueue(x->rc);
    }
}
