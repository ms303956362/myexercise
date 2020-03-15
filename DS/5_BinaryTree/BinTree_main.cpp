#include <iostream>
using std::cout;
using std::endl;

#include "BinTree.h"

int main(int argc, char const *argv[])
{
    // 测试节点插入
    cout << "test BinNode insert & size" << endl;
    BinNodePosi<int> r = new BinNode<int>(1);
    auto l1 = r->insertAsLC(2);
    auto l2 = l1->insertAsLC(3);
    l1->insertAsRC(4);
    l2->insertAsRC(5);
    cout << r->size() << endl;
    cout << endl;
    // 测试树插入
    cout << "test BinTree insert" << endl;
    BinTree<int> t;
    auto tr = t.insertAsRoot(1);
    auto tlc1 = t.insertAsLC(tr, 2);
    t.insertAsRC(tr, 3);
    t.insertAsRC(tlc1, 4);
    t.insertAsLC(tlc1, 5);
    cout << t.root()->height << endl;
    cout << endl;
    return 0;
}
