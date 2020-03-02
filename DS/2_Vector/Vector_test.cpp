#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

#include "Vector.h"

template<typename T>
ostream& printVector(Vector<T> v, ostream& os = cout) {
    for (auto i = 0; i != v.size(); ++i){
        os << v[i] << " ";
    }
    os << endl;
    return os;
}

int main(int argc, char const *argv[])
{
    Vector<int> v;
    /****************测试size和empty*****************/
    cout << "test size and empty" << endl;
    cout << v.size() << " " << v.empty() << endl;
    cout << endl;
    /*******************测试insert******************/
    cout << "test insert" << endl;
    v.insert(0, 1);
    v.insert(4);
    v.insert(1, 2);
    v.insert(5);
    v.insert(2, 3);
    v.insert(6);
    printVector(v) << endl;
    /*******************测试remove******************/
    cout << "test remove" << endl;
    v.remove(0, 2);
    printVector(v) << endl;
    /*******************测试find*******************/
    cout << "test find" << endl;
    cout << "element '3' is at: " << v.find(3) << endl;
    cout << "element '2' is at: " << v.find(2) << endl;
    cout << endl;
    /****************测试deduplicate**************/
    cout << "test deduplicate" << endl;
    v.deduplicate();
    printVector(v);
    v.insert(3, 3);
    v.insert(6);
    v.insert(5);
    printVector(v);
    cout << "decreasement of len(v): " << v.deduplicate() << endl;
    printVector(v) << endl;
    /*****************测试uniquify***************/
    cout << "test uniquify" << endl;
    v.uniquify();
    printVector(v);
    v.insert(0, 3);
    v.insert(0, 3);
    v.insert(5, 5);
    v.insert(6);
    v.insert(6);
    printVector(v);
    cout << "decreasement of len(v): " << v.uniquify() << endl;
    printVector(v) << endl;
    return 0;
}
