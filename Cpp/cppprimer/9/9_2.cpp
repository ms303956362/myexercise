#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <string>
using std::string;

bool find_val(vector<int>::iterator begin, vector<int>::iterator end, int val){
    bool is_found = false;
    for (auto p = begin; p != end; ++p){
        if (*p == val){
            is_found = true;
            break;
        }
    }
    return is_found;
}

vector<int>::iterator find_val_iterator(vector<int>::iterator begin, vector<int>::iterator end, int val){
    vector<int>::iterator p;
    for (p = begin; p != end; ++p){
        if (*p == val)
            break;
    }
    if (p == end)
        cerr << "not found" << endl;
    return p;
}

ostream& print_vecint(ostream& os, vector<int>& iv){
    for (auto i : iv)
        os << i << " ";
    return os;
}

int main(int argc, char const *argv[])
{
    // 9.4
    // vector<int> iv{1, 2, 3, 4, 5};
    // cout << find_val(iv.begin(), iv.end(), 3) << endl;
    // cout << find_val(iv.begin() + 2, iv.end(), 2) << endl;

    // 9.5
    // vector<int> iv{1, 2, 3, 4, 5};
    // vector<int>::iterator p;
    // p = find_val_iterator(iv.begin(), iv.end(), 3);
    // if (p != iv.end())
    //     cout << "found at " << p - iv.begin() << " positions after the given begining index" << endl;
    // p = find_val_iterator(iv.begin() + 2, iv.end() - 1, 2);
    // if (p != iv.end() - 1)
    //     cout << "found at " << p - iv.begin() - 2 << " positions after the given begining index"  << endl;

    // 9.11
    // vector<int> iv1;
    // vector<int> iv2{1, 2, 3, 4, 5};
    // vector<int> iv3(iv2);
    // vector<int> iv4(iv2.begin() + 1, iv2.end() - 2);
    // vector<int> iv5(6);
    // vector<int> iv6(6, 1);
    // cout << "vector<int> iv1;" << endl;
    // print_vecint(cout, iv1) << endl;
    // cout << "vector<int> iv2{1, 2, 3, 4, 5};" << endl;
    // print_vecint(cout, iv2) << endl;
    // cout << "vector<int> iv3(iv2);" << endl;
    // print_vecint(cout, iv3) << endl;
    // cout << "vector<int> iv4(iv2.begin() + 1, iv2.end() - 2);" << endl;
    // print_vecint(cout, iv4) << endl;
    // cout << "vector<int> iv5(6);" << endl;
    // print_vecint(cout, iv5) << endl;
    // cout << "vector<int> iv6(6, 1);" << endl;
    // print_vecint(cout, iv6) << endl;

    // 9.13
    // list<int> il{1, 2, 3};
    // vector<double> dv(il.begin(), il.end());
    // for (auto i : il)
    //     cout << i << " ";
    // cout << endl;
    // for (auto d : dv)
    //     cout << d << " ";
    // cout << endl;

    // vector<int> iv{1, 2, 3, 4, 5};
    // vector<double> dv2(iv.begin(), iv.end());
    // for (auto i : iv)
    //     cout << i << " ";
    // cout << endl;
    // for (auto d : dv2)
    //     cout << d << " ";
    // cout << endl;

    // 9.14
    // list<const char *> cpl{"abc", "def", "ghi"};
    // vector<string> sv;
    // sv.assign(cpl.begin(), cpl.end());
    // for (const auto& s : cpl){
    //     cout << s << " ";
    // }
    // cout << endl;
    // for (const auto& s : sv){
    //     cout << s << " ";
    // }
    // cout << endl;

    // 9.15
    // vector<int> v1 = {1, 2, 3};
    // vector<int> v2 = {1, 2, 3, 4, 5};
    // if (v1==v2){
    //     cout << "same" << endl;
    // } else {
    //     cout << "not same" << endl;
    // }

    // 9.16
    list<int> il{1, 2, 3};
    vector<int> iv{1, 2, 3, 4, 5};
    vector<int> iv2(il.begin(), il.end());
    if (iv == iv2)
        cout << "same" << endl;
    else if (iv < iv2)
        cout << "less" << endl;
    else
        cout << "greater" << endl;

    return 0;
}
