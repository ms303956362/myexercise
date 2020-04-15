#include "AVL.h"
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    BST<int> bst;
    auto vst = [](int x) { cout << x << " "; };
    // 测试插入
    cout << "test insert" << endl;
    bst.insert(36);
    bst.insert(27);
    bst.insert(58);
    bst.insert(6);
    bst.insert(69);
    bst.insert(53);
    bst.insert(40);
    bst.insert(64);
    bst.insert(46);
    bst.travIn(vst);
    cout << endl << endl;
    // 测试搜索
    cout << "test search" << endl;
    auto x = bst.search(58);
    cout << "node " << x->data << ": parent = " << x->parent->data << "  left child = " << x->lc->data << "  right child = " << x->rc->data << endl << endl;
    // 测试删除
    cout << "test remove" << endl;
    bst.remove(69);
    bst.remove(36);
    bst.travIn(vst);
    cout << endl << endl;
    // 测试AVL构建树
    cout << "test AVL building" << endl;
    AVL<int> avl;
    avl.insert(36);
    avl.insert(27);
    avl.insert(58);
    avl.insert(6);
    avl.insert(53);
    avl.insert(69);
    avl.insert(46);
    cout << "Initialized AVL Tree" << endl;
    avl.travIn(vst);
    cout << endl;
    cout << "height: " << avl.root()->height << endl << endl;
    cout << "test AVL insert" << endl;
    // 测试AVL树插入
    avl.insert(40);
    avl.travIn(vst);
    cout << endl;
    cout << "height: " << avl.root()->height << endl << endl;
    // 测试AVL树删除
    cout << "test AVL remove" << endl;
    avl.remove(53);
    avl.travIn(vst);
    cout << endl;
    cout << "height: " << avl.root()->height << endl << endl;
    avl.remove(69);
    avl.travIn(vst);
    cout << endl;
    cout << "height: " << avl.root()->height << endl << endl;
    return 0;
}
