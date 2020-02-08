#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include "my_Sales_data.h"
#include "my_String.h"
#include "my_StrVec.h"
#include "my_StrBlob.h"

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
    my_String s1("abc"), s2("def"), s3("abc");
    cout << (s1 == s2) << (s1 == s3) << (s1 != s2) << endl;
    MyStrBlob sb1{"abc", "def"}, sb2{"abc"}, sb3{"abc", "def", "ghi"}, sb4{"abc", "def"}, sb5{"ghi"};
    cout << (sb1 == sb2) << (sb1 == sb3) << (sb1 != sb4) << (sb1 != sb5) << endl;
    My_StrVec sv1{"abc", "def"}, sv2{"abc"}, sv3{"abc", "def", "ghi"}, sv4{"abc", "def"}, sv5{"ghi"};
    cout << (sv1 == sv2) << (sv1 == sv3) << (sv1 != sv4) << (sv1 != sv5) << endl;

    return 0;
}
