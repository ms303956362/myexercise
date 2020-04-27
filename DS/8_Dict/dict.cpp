#include <iostream>
using std::cout;
using std::endl;

#include "Bitmap.h"
#include "Hashtable.h"

int main(int argc, char const *argv[])
{
    // 测试Bitmap
    cout << "test Bitmap" << endl;
    Bitmap b(5);
    b.set(0);
    b.set(7);
    cout << b.test(0) << b.test(6) << b.test(7) << endl;
    b.clear(0);
    b.clear(8);
    cout << b.test(0) << b.test(7) << b.test(9) << b.test(16) << endl << endl;
    // 测试Hashtable
    HashTable<const char*, int> ht(7);
    ht.put("abc", 1);
    int *p = ht.get("abc");
    if (p)
        ++*p;
    ht.put("defgh", 1);
    ht.remove("abde");
    ht.remove("abc");
    p = ht.get("abc");
    if (p)
        ++*p;
    p = ht.get("defgh");
    if (p)
        ++*p;
    cout << *ht.get("defgh") << endl;
    return 0;
}
