#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

#include "my_StrVec.h"
#include "my_String.h"

template <typename T>
ostream& print_seq(ostream& os, const T& seq){
    for (auto iter = seq.begin(); iter != seq.end();++iter){
        if (!iter->empty())
            os << *iter << " ";
        else
            os << "???" << " ";
    }
    return os;
}

int main(int argc, char const *argv[])
{
    // 13.39
    // My_StrVec msv1{"cao", "ni", "ma"}, msv2;
    // My_StrVec msv3(msv1);
    // msv1.push_back("zhen de");
    // msv2 = msv1;
    // msv2.push_back("shuang");
    // print_seq(cout, msv1) << endl;
    // print_seq(cout, msv2) << endl;
    // print_seq(cout, msv3) << endl;
    // msv3.push_back("bi");
    // msv3.reserve(5);
    // cout << "capacity after \"msv3.reserve(5)\": " << msv3.capacity() << endl;
    // msv3.reserve(12);
    // cout << "capacity after \"msv3.reserve(12)\": " << msv3.capacity() << endl;
    // msv3.resize(3);
    // cout << "elements after \"msv3.resize(3)\": ";
    // print_seq(cout, msv3) << endl;
    // msv3.resize(5);
    // cout << "elements after \"msv3.resize(5)\": ";
    // print_seq(cout, msv3) << endl;
    // msv3.resize(8);
    // cout << "capacity after \"msv3.resize(8)\": " << msv3.capacity() << endl;
    // cout << "elements after \"msv3.resize(8)\": ";
    // print_seq(cout, msv3) << endl;

    // 13.44
    // my_String s1;
    // my_String s2("abc");
    // my_String s3(s2);
    // s1 = s2;
    
    return 0;
}
