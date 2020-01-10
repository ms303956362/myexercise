#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
    // 4.10
    // int i;
    // while (cin >> i && i != 42)
    //     ;

    // 4.21
    // vector<int> v{0, 1, -1, 2, 4, 3, 7, 9, 62, 33};
    // for (auto &i : v){
    //     i = i % 2 ? 2 * i : i;
    //     cout << i << " ";
    // }
    // cout << endl;

    // 4.22
    // unsigned int i;
    // vector<unsigned int> grades;
    // string finalgrade;
    // while (cin >> i)
    //     grades.push_back(i);
    // cout << "=====" << " use ? : "<<"======" << endl;
    // for (auto grade:grades){
    //     finalgrade = grade > 90 ? "high pass" : grade > 75 ? "pass" : grade > 60 ? "low pass" : "fail";
    //     cout << grade << " " << finalgrade << endl;
    // }
    // cout << "=====" << " use if "<<"======" << endl;
    // for (auto grade:grades){
    //     if (grade > 90)
    //         finalgrade = "high pass";
    //     else if (grade > 75)
    //         finalgrade = "pass";
    //     else if (grade > 60)
    //         finalgrade = "low pass";
    //     else
    //         finalgrade = "fail";
    //     cout << grade << " " << finalgrade << endl;
    // }

    // 4.28
    // cout << "size of bool: " << sizeof(bool) << endl;
    // cout << "size of char: " << sizeof(char) << endl;
    // cout << "size of wchar_t: " << sizeof(wchar_t) << endl;
    // cout << "size of char16_t: " << sizeof(char16_t) << endl;
    // cout << "size of char32_t: " << sizeof(char32_t) << endl;
    // cout << "size of short: " << sizeof(short) << endl;
    // cout << "size of int: " << sizeof(int) << endl;
    // cout << "size of long: " << sizeof(long) << endl;
    // cout << "size of long long: " << sizeof(long long) << endl;
    // cout << "size of float: " << sizeof(float) << endl;
    // cout << "size of double: " << sizeof(double) << endl;
    // cout << "size of long double: " << sizeof(long double) << endl;

    // 4.29
    // int x[10];
    // int *p = x;
    // cout << sizeof(x) / sizeof(*x) << endl;
    // cout << sizeof(p) / sizeof(*p) << endl;

    // 4.31
    vector<int> ivec(10, 0);
    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size();ix++, cnt--)
        ivec[ix] = cnt;
    for (auto i : ivec)
        cout << i << " ";
    cout << endl;

    return 0;
}
