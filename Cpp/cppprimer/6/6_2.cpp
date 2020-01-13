#include <iostream>
#include <string>
#include <initializer_list>

using std::cin;
using std::cout;
using std::endl;
using std::initializer_list;
using std::string;

bool is_upper(const string& s){
    for (auto ch : s){
        if (isupper(ch))
            return true;
    }
    return false;
}

void to_lower(string &s){
    for (auto &ch : s){
        if (isupper(ch))
            ch = tolower(ch);
    }
}

inline
int compare_int(int i1, int* pi2){
    return i1 > *pi2 ? i1 : *pi2;
}

void swap_ptr(int *&rp1, int *&rp2){
    int *tmp;
    tmp = rp1;
    rp1 = rp2;
    rp2 = tmp;
}

void print(int i){
    cout << i << endl;
}

void print(int (&a)[2]){
    for (auto i : a)
        cout << i << " ";
    cout << endl;
}

int sum(initializer_list<int> il){
    int s = 0;
    for (auto it : il)
        s += it;
    return s;
}

int main(int argc, char const *argv[])
{
    // 6.17
    // string s = "AbC";
    // cout << s << endl;
    // cout << is_upper(s) << endl;
    // to_lower(s);
    // cout << s << endl;
    // cout << is_upper(s) << endl;

    // 6.21
    // int i1 = 1, i2 = -1;
    // cout << compare_int(i1, &i2) << endl;

    // 6.22
    // int i1 = 1, i2 = 2;
    // int *pi1 = &i1, *pi2 = &i2;
    // swap_ptr(pi1, pi2);
    // cout << *pi1 << " " << *pi2 << endl;

    // 6.23
    // int i = 2, j[2] = {0, 1};
    // print(i);
    // print(j);

    // 6.25
    // string s;
    // for (int i = 0; i != argc; ++i){
    //     if (i != 0)
    //         s += " ";
    //     s += string(argv[i]);
    // }
    // cout << argc << ": " << s << endl;

    // 6.27
    int s;
    s = sum({1, 2, 3, 4, 5});
    cout << s << endl;

    return 0;
}
