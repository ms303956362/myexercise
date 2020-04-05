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
    return 0;
}
