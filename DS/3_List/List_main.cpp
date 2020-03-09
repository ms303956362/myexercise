#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

#include "List.h"

template <typename T>
ostream& printList(List<T>& l, ostream& os=cout) {
    Posi<T> p = l.first();
    while (p != l.last()->succ) {
        os << p->data << " ";
        p = p->succ;
    }
    return os;
}

int main(int argc, char const *argv[])
{
    /**************测试ListNode*************/
    cout << "test ListNode" << endl;
    ListNode<int> n1(1);
    Posi<int> head = &n1;
    head->insertAsSucc(3);
    head->succ->insertAsPred(2);
    cout << head->data << head->succ->data << head->succ->succ->data << endl;
    cout << endl;

    /**********测试insert、remove**********/
    cout << "test insert remove" << endl;
    List<int> l0;
    l0.insertAsLast(3);
    l0.insertAsLast(5);
    l0.insertAsFirst(1);
    l0.insertB(l0.last(), 4);
    l0.insertA(l0.first(), 2);
    Posi<int> p0 = l0.first();
    List<int> l1(p0->succ, 2);
    List<int> l2(l0, 2, 3);
    List<int> l3(l0);
    printList(l0) << endl;
    printList(l1) << endl;
    printList(l2) << endl;
    printList(l3) << endl;
    cout << l3.remove(l3.first()->succ) << endl;
    cout << endl;

    /************测试find、search***********/
    cout << "test find search" << endl;
    cout << (l3.find(2) == nullptr) << endl;
    Posi<int> p5 = l3.find(5);
    cout << p5->data << endl;
    cout << (l3.find(1, 2, p5) == nullptr) << endl;
    l3.insertA(l3.search(2), 2);
    l3.insertA(l3.search(0), 0);
    printList(l3) << endl;
    cout << endl;

    /*******测试deduplicate、uniquify*******/
    cout << "test deduplicate uniquify" << endl;
    l3.insertAsFirst(3);
    l3.insertAsLast(5);
    printList(l3) << endl;
    l3.deduplicate();
    printList(l3) << endl;
    l3.insertAsFirst(0);
    l3.insertA(l3.first()->succ->succ, 2);
    l3.insertB(l3.last()->pred, 3);
    printList(l3) << endl;
    l3.uniquify();
    printList(l3) << endl;
    cout << endl;

    /***************测试sort**************/
    List<int> l;
    int a[5] = {3, 4, 2, 5, 1};
    for (int i = 0; i != 5; ++i) {
        l.insertAsLast(a[i]);
    }
    printList(l) << endl;
    l.sort();
    printList(l) << endl;
    cout << endl;

    /**************测试reverse************/
    cout << "test reverse" << endl;
    l.reverse();
    printList(l) << endl;
    l.insertAsLast(0);
    l.reverse();
    printList(l) << endl;
    cout << endl;

    return 0;
}
