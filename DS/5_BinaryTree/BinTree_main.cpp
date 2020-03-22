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
    cout << r->size() << endl << endl;

    // 测试树插入
    cout << "test BinTree insert" << endl;
    BinTree<int> t;
    auto tr = t.insertAsRoot(1);
    auto tlc1 = t.insertAsLC(tr, 2);
    auto trc1 = t.insertAsRC(tr, 3);
    t.insertAsRC(tlc1, 4);
    t.insertAsLC(tlc1, 5);
    cout << t.root()->height << endl << endl;

    // 测试分离子树
    cout << "test secede attach" << endl;
    cout << t.root()->lc->height << " " << t.root()->rc->height << endl;
    BinTree<int>* stl = t.secede(tlc1), *str = t.secede(trc1);
    cout << stl->root()->height << " " << str->root()->height << endl;
    t.attachAsLC(t.root(), str);
    t.attachAsRC(t.root(), stl);
    cout << t.root()->lc->height << " " << t.root()->rc->height << endl << endl;

    // 测试先序遍历
    cout << "test preorder" << endl;
    BinTree<char> tc;
    tc.insertAsRoot('a');
    tc.insertAsLC(tc.root(), 'b');
    auto tc1r = tc.insertAsRC(tc.root(), 'c');
    auto tc2l = tc.insertAsLC(tc1r, 'd');
    auto tc2r = tc.insertAsRC(tc1r, 'f');
    tc.insertAsRC(tc2l, 'e');
    tc.insertAsLC(tc2r, 'g');
    auto vst = [](char c) { cout << c << " ";};
    tc.travPre(vst);
    cout << endl << endl;

    // 测试中序遍历
    cout << "test inorder" << endl;
    BinTree<char> tcc;
    tcc.insertAsRoot('b');
    auto tcc1r = tcc.insertAsRC(tcc.root(), 'f');
    tcc.insertAsLC(tcc.root(), 'a');
    auto tcc2l = tcc.insertAsLC(tcc1r, 'd');
    tcc.insertAsRC(tcc1r, 'g');
    tcc.insertAsLC(tcc2l, 'c');
    tcc.insertAsRC(tcc2l, 'e');
    tcc.travIn(vst);
    cout << endl << endl;

    // 测试succ
    cout << "test succ" << endl;
    BinNodePosi<char> xcc = tcc.root();
    while (xcc->lc)
        xcc = xcc->lc;
    do {
        vst(xcc->data);
        xcc = xcc->succ();
    } while (xcc);
    cout << endl << endl;

    // 测试后序遍历
    cout << "test post order" << endl;
    BinTree<char> tccc;
    tccc.insertAsRoot('k');
    tccc.insertAsRC(tccc.root(), 'j');
    auto tcccl = tccc.insertAsLC(tccc.root(), 'i');
    auto tccc1l = tccc.insertAsRC(tcccl, 'h');
    auto tccc2r = tccc.insertAsRC(tccc1l, 'g'), tccc2l = tccc.insertAsLC(tccc1l, 'b');
    tccc.insertAsRC(tccc2l, 'a');
    auto tccc3l = tccc.insertAsLC(tccc2r, 'e');
    tccc.insertAsRC(tccc2r, 'f');
    tccc.insertAsLC(tccc3l, 'c');
    tccc.insertAsRC(tccc3l, 'd');
    tccc.travPost(vst);
    cout << endl << endl;

    // 层次遍历
    cout << "test level" << endl;
    BinTree<char> ct;
    ct.insertAsRoot('a');
    auto ct1l = ct.insertAsLC(ct.root(), 'b');
    ct.insertAsLC(ct1l, 'c');
    auto ct2r = ct.insertAsRC(ct1l, 'd');
    ct.insertAsRC(ct2r, 'f');
    auto ct3l = ct.insertAsLC(ct2r, 'e');
    ct.insertAsRC(ct3l, 'g');
    ct.travLevel(vst);
    cout << endl << endl;

    return 0;
}
