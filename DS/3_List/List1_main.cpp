#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include "List1.h"

template <typename T>
ostream& printList(List<T>& l, ostream& os=cout) {
    Pos p = l.first();
    while (p != l.succ(l.last())) {
        os << l.elem(p) << " ";
        p = l.succ(p);
    }
    return os;
}

int main(int argc, char const *argv[])
{
    cout << "test only read function" << endl;
    List<int> l(8);
    cout << l.size() << l.empty() << l.valid(2) << endl;
    cout << endl;

    cout << "test insert" << endl;
    Pos pl = l.insertAsLast(3);
    Pos pf = l.insertAsFirst(0);
    l.insertA(pf, 1);
    l.insertB(pl, 2);
    printList(l) << endl;
    cout << endl;

    cout << "test remove" << endl;
    l.remove(pl);
    l.remove(pf);
    printList(l) << endl;
    cout << endl;

    cout << "test reverse" << endl;
    l.insertAsLast(4);
    l.insertA(l.succ(l.first()), 5);
    l.insertAsLast(6);
    l.insertB(l.pred(l.last()), 7);
    printList(l) << endl;
    l.reverse(l.succ(l.first()), l.pred(l.last()));
    l.remove(l.first());
    l.remove(l.last());
    printList(l) << endl;
    cout << endl;
    return 0;
}
