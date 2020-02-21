#include <iostream>
using std::cout;
using std::endl;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Sales_data.h"

template <typename T>
int compare(const T& item1, const T& item2) {
    if (item1 < item2)
        return -1;
    else if (item1 > item2)
        return 1;
    else
        return 0;
}

template <typename T, typename V>
T find(const T& beg, const T& end, const V& val) {
    auto iter = beg;
    for (; iter != end; ++iter) {
        if (*iter == val)
            break;
    }
    return iter;
}

template <typename T, size_t N>
void print(T (&arr)[N]) {
    for (auto e : arr)
        cout << e << " ";
    cout << endl;
}

template <typename T, size_t N>
T* Begin(T (&arr)[N]) {
    return arr;
}

template <typename T, size_t N>
T* End(T (&arr)[N]) {
    return arr + N;
}

template <typename T, size_t N>
constexpr size_t get_size(T (&arr)[N]) {
    return N;
}

int main(int argc, char const *argv[])
{
    // 16.2
    // int i1 = 0, i2 = 1;
    // string s1 = "abc", s2 = "acb";
    // cout << "Integer compare: " << compare(i1, i2) << endl;
    // cout << "String compare: " << compare(s1, s2) << endl;
    
    // 16.3
    // Sales_data sd1("abc"), sd2("def");
    // cout << "Sales_data compare: " << compare(sd1, sd2) << endl;

    // 16.4
    // vector<int> iv{1, 3, 2, 4, 5, 7, 6};
    // list<string> sl{"abc", "def", "acd", "bef", "ghi"};
    // cout << *find(iv.begin(), iv.end(), 7) << endl;
    // cout << *find(sl.begin(), sl.end(), "acd") << endl;

    // 16.5
    // int a[2] = {0, 1};
    // string b[3]{"abc", "def", "ghi"};
    // print(a);
    // print(b);

    // 16.6
    int a[3] = {1, 2, 3};
    for (auto p = Begin(a); p != End(a); ++p){
        cout << *p << " ";
    }
    cout << endl;

    // 16.7
    // int a[2];
    // string b[get_size(a)];
    // cout << get_size(b) << endl;

    return 0;
}
