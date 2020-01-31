#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstring>
using std::strlen;

#include <memory>
using std::allocator;

int main(int argc, char const *argv[])
{
    // 12.23
    // const char *s1 = "caoni", *s2 = "ma";
    // char *s3 = new char[strlen(s1) + strlen(s2) + 1]();
    // strcat(s3, s1);
    // strcat(s3, s2);
    // cout << s1 << " + " << s2 << " = " << s3 << endl;
    // delete[] s3;

    // const string s4 = "cao", s5 = "nima";
    // char *s6 = new char[s4.size() + s5.size() + 1]();
    // strcpy(s6, (s4 + s5).c_str());
    // cout << s4 << " + " << s5 << " = " << s6 << endl;
    // delete[] s6;

    // 12.24
    // string s;
    // while (cin >> s){
    //     char *p = new char[s.size() + 1]();
    //     strcpy(p, s.c_str());
    //     cout << p << endl;
    //     delete[] p;
    // }

    // 12.26
    size_t n = 10;
    allocator<string> a;
    auto const p = a.allocate(n);
    auto q = p;
    string s;
    while (cin >> s && q != p + n){
        a.construct(q++, s);
    }
    const size_t size = q - p;
    for (auto iter = p; iter != p + size; ++iter){
        cout << *iter << " ";
    }
    while (q != p){
        a.destroy(--q);
    }
    a.deallocate(p, n);

    return 0;
}
