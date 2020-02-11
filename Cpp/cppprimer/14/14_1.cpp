#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <algorithm>
using std::for_each;

#include "my_Sales_data.h"
#include "my_String.h"
#include "my_StrVec.h"
#include "my_StrBlob.h"

class PtrMyStrBlobPtr{
private:
    MyStrBlobPtr *p=nullptr;
public:
    PtrMyStrBlobPtr() = default;
    PtrMyStrBlobPtr(MyStrBlobPtr& pmsb) : p(&pmsb){};
    MyStrBlobPtr &operator*(){
        return *p;
    }
    MyStrBlobPtr *operator->(){
        return p;
    }
};

int main(int argc, char const *argv[])
{
    // 14.2
    // ifstream ifs("data/book_sales");
    // Sales_data total(ifs);
    // if (ifs){
    //     Sales_data trans;
    //     while (ifs >> trans){
    //         if (total.isbn() == trans.isbn()){
    //             total += trans;
    //         } else {
    //             cout << total << endl;
    //             total = trans;
    //         }
    //     }
    //     cout << total << endl;
    // } else {
    //     cerr << "no data input" << endl;
    // }

    // 14.7
    // my_String s("abc");
    // cout << s << endl;

    // 14.11
    // Sales_data item;
    // cin >> item;
    // cout << item;

    // 14.16
    // my_String s1("abc"), s2("def"), s3("abc");
    // cout << (s1 == s2) << (s1 == s3) << (s1 != s2) << endl;
    // MyStrBlob sb1{"abc", "def"}, sb2{"abc"}, sb3{"abc", "def", "ghi"}, sb4{"abc", "def"}, sb5{"ghi"};
    // cout << (sb1 == sb2) << (sb1 == sb3) << (sb1 != sb4) << (sb1 != sb5) << endl;
    // My_StrVec sv1{"abc", "def"}, sv2{"abc"}, sv3{"abc", "def", "ghi"}, sv4{"abc", "def"}, sv5{"ghi"};
    // cout << (sv1 == sv2) << (sv1 == sv3) << (sv1 != sv4) << (sv1 != sv5) << endl;

    // 14.18
    // my_String s1("abc"), s2("acb"), s3("abcd");
    // cout << (s1 < s2) << (s1 < s3) << (s2 < s3) << endl;
    // MyStrBlob sb1{"abc"}, sb2{"abc", "def"}, sb3{"abc", "cde", "ghi"}, sb4{"ghi"};
    // cout << (sb1 < sb2) << (sb2 < sb3) << (sb3 < sb4) << endl;
    // My_StrVec sv1{"abc"}, sv2{"abc", "def"}, sv3{"abc", "cde", "ghi"}, sv4{"ghi"};
    // cout << (sv1 < sv2) << (sv2 < sv3) << (sv3 < sv4) << endl;
    // MyStrBlobPtr p1 = sb2.begin(), p2 = sb2.end(), p3 = sb2.begin();
    // cout << (p1 < p2) << (p1 != p2) << (p1 == p3) << endl;

    // 14.22
    // Sales_data s;
    // s = "abc";
    // cout << s << endl;

    // 14.23
    // My_StrVec sv;
    // sv = {"abc", "def", "ghi"};
    // for (auto iter = sv.begin(); iter != sv.end();++iter){
    //     cout << *iter << " ";
    // }
    // cout << endl;

    // 14.26
    // My_StrVec sv{"abc", "def", "ghi"};
    // MyStrBlob sb{"abc", "def", "ghi"};
    // my_String s("caonima");
    // cout << s[3] << endl;
    // cout << sb[1] << endl;
    // cout << sv[0] << endl;

    // 14.27
    // MyStrBlob sb{"abc", "def", "ghi"};
    // for (auto iter = sb.begin(); iter != sb.end();++iter){
    //     cout << iter.deref() << " ";
    // }
    // cout << endl;
    // for (auto iter = sb.cend(); iter != sb.cbegin();){
    //     cout << (--iter).deref() << " ";
    // }
    // cout << endl;

    // 14.28
    // MyStrBlob sb{"abc", "def", "ghi"};
    // auto p1 = sb.begin(), iter = p1;
    // auto cp1 = sb.cbegin(), citer = cp1;
    // cout << iter.deref() << " ";
    // iter = p1 + 1;
    // cout << iter.deref() << " ";
    // iter += 1;
    // cout << iter.deref() << " ";
    // p1 = iter - 1;
    // cout << p1.deref() << " ";
    // p1 -= 1;
    // cout << p1.deref() << " ";
    // cout << iter - p1 << " " << p1 - iter << endl;
    // cout << citer.deref() << " ";
    // citer = cp1 + 1;
    // cout << citer.deref() << " ";
    // citer += 1;
    // cout << citer.deref() << " ";
    // cp1 = citer - 1;
    // cout << cp1.deref() << " ";
    // cp1 -= 1;
    // cout << cp1.deref() << " ";
    // cout << citer - cp1 << " " << cp1 - citer << endl;

    // 14.30
    // MyStrBlob sb{"abc", "cdef", "efghi"};
    // for (auto iter = sb.begin(); iter != sb.end();++iter){
    //     cout << *iter << " ";
    // }
    // cout << endl;
    // for (auto iter = sb.cend(); iter != sb.cbegin();){
    //     cout << (--iter)->size() << " ";
    // }
    // cout << endl;

    // 14.32
    MyStrBlob sb{"abc", "cdef", "efghi"};
    auto pmsb = sb.begin();
    PtrMyStrBlobPtr ppmsb(pmsb);
    cout << ppmsb->operator*() << endl;

    return 0;
}
