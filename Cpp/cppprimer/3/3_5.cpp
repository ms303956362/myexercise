#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cstring>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
    // 3.31
    // int a[10] = {};
    // for (size_t i = 0; i < 10; ++i){
    //     a[i] = i;
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    // 3.32
    // vector<int> v(10, 0);
    // for (decltype(v.size()) i = 0; i != v.size(); ++i){
    //     v[i] = i;
    //     cout << v[i] << " ";
    // }
    // cout << endl;

    // 3.35
    // int a[3] = {1, 1, 1};
    // int *b = begin(a), *e = end(a);
    // for (int *p = b; p != e; ++p)
    //     *p = 0;
    // for (auto i : a)
    //     cout << i << " ";
    // cout << endl;

    // 3.36a
    // int a[3] = {1, 1, 1}, b[3] = {1, 1, 1};
    // int *ab = begin(a), *ae = end(a), *bb = begin(b), *be = end(b);
    // int *pa = ab, *pb = bb;
    // if (ae-ab != be-bb){
    //     cout << "not same" << endl;
    // } else {
    //     for (pa = ab, pb = bb; pa != ae && pb != be && *pa == *pb; ++pa, ++pb)
    //         ;
    //     if (pa != ae || pb != be)
    //         cout << "not same" << endl;
    //     else
    //         cout << "same" << endl;
    // }

    // 3.36b
    // vector<int> v1{1, 1, 1}, v2{1, 1, 1};
    // auto p1 = v1.begin(), p2 = v2.begin();
    // if (v1.end() - v1.begin() != v2.end() - v2.begin())
    //     cout << "not same" << endl;
    // else {
    //     for (p1 = v1.begin(), p2 = v2.begin(); p1 != v1.end() && p2 != v2.end() && *p1 == *p2; ++p1, ++p2)
    //         ;
    //     if (p1 != v1.end() || p2 != v2.end())
    //         cout << "not same" << endl;
    //     else
    //         cout << "same" << endl;
    // }

    // 3.39a
    // string s1, s2;
    // cin >> s1 >> s2;
    // if (s1 > s2)
    //     cout << s1 << " is greater than " << s2 << endl;
    // else if (s1 == s2)
    //     cout << s1 << " is equal to " << s2 << endl;
    // else
    //     cout << s1 << " is less than " << s2 << endl;

    // 3.39b
    // char cs1[10], cs2[10];
    // cin >> cs1 >> cs2;
    // if (strcmp(cs1, cs2) > 0)
    //     cout << cs1 << " is greater than " << cs2 << endl;
    // else if (strcmp(cs1, cs2) == 0)
    //     cout << cs1 << " is equal to " << cs2 << endl;
    // else
    //     cout << cs1 << " is less than " << cs2 << endl;

    // 3.40
    // const char *s1 = "abc", *s2 = "def";
    // const auto len = strlen(s1) + strlen(s2) + 1;
    // char s[len];
    // strcpy(s, s1);
    // strcat(s, s2);
    // cout << s << endl;

    // 3.41
    // int a[3] = {0, 1, 2};
    // vector<int> v(begin(a), end(a));
    // for(auto i : v)
    //     cout << i << " ";
    // cout << endl;

    // 3.42
    vector<int> v(10, 3);
    int a[10] = {0};
    for (int i = 0; i != 10; ++i)
        a[i] = v[i];
    for (auto i : a)
        cout << i << " ";
    cout << endl;

    return 0;
}
