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
    BinNodePosi<T> succ() const; // 中序遍历时的后继
    // 读写函数
    BinNodePosi<T> insertAsLC(const T &e); // 作为左孩子节点插入
    BinNodePosi<T> insertAsRC(const T &e); // 作为右孩子节点插入
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