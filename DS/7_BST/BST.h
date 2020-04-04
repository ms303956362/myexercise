#include "BinTree.h"

template <typename T>
class BST : public BinTree<T> {
protected:
    BinNodePosi<T> _hot; // 搜索命中节点的父节点
    BinNodePosi<T> connect34(BinNodePosi<T> a, BinNodePosi<T> b, BinNodePosi<T> c,
                             BinNodePosi<T> T0, BinNodePosi<T> T1, BinNodePosi<T> T2, BinNodePosi<T> T3);
    BinNodePosi<T> rotateAt(BinNodePosi<T> x);  // 确定a,b,c,T0,T1,T2,T3后3+4重构的统一实现

public:
    virtual BinNodePosi<T> &search(const T &e);
    virtual BinNodePosi<T> insert(const T &e);
    virtual bool remove(const T &);
};


/*************************公开接口****************************/
template <typename T>
BinNodePosi<T> &BST<T>::search(const T &e) { // 无论是否成功，_hot为查找元素的父节点，返回值为查找元素的节点
    return searchIn(this->_root, e, _hot);
}

template <typename T>
BinNodePosi<T> BST<T>::insert(const T &e) {
    BinNodePosi<T> x = search(e);
    if (!x) {
        x = new BinNode<T>(e, _hot);
        ++this->_size;
        updateHeightAbove(x);
    }
    return x;
}

template <typename T>
bool BST<T>::remove(const T& e) {
    BinNodePosi<T> x = search(e);
    if (!x) 
        return false;
    removeAt(x, _hot);
    --this->_size;
    updateHeightAbove(_hot);
    return true;
}

/*************************静态方法***************************/
template <typename T>
static BinNodePosi<T>& searchIn(BinNodePosi<T>& v, const T& e, BinNodePosi<T>& hot) { // 限定本文件调用
    if (!v || v->data == e) { // 树根
        return v;
    }
    BinNodePosi<T> c = v;
    do {
        hot = c;
        c = hot->data < e ? hot->rc : hot->lc;
    } while (c && c->data != e);
    return c;  // （1）查找成功：c指向查找元素 （2）查找失败：c指向可插入的位置
}

template <typename T>
static BinNodePosi<T> removeAt(BinNodePosi<T>& x, BinNodePosi<T>& hot) {
    BinNodePosi<T> w; // 实际被删除节点
    BinNodePosi<T> succ; // 顶替的节点
    
}