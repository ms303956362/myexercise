#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
    // 3.14
    // vector<int> v;
    // int i;
    // while (cin >> i)
    //     v.push_back(i);
    
    // 3.15
    // vector<string> text;
    // string s;
    // while (cin >> s)
    //     text.push_back(s);

    // 3.16
    // vector<string> v{10, "hi"};
    // cout << v.size() << endl;
    // for (auto i : v)
    //     cout << i << " ";
    // cout << endl;

    // 3.17
    // vector<string> text;
    // string s;
    // while (cin >> s)
    //     text.push_back(s);
    // for (auto &s1 : text){
    //     for (auto &c : s1)
    //         c = toupper(c);
    //     cout << s1 << endl;
    // }

    // 3.20
    vector<int> v;
    int num;
    while (cin >> num)
        v.push_back(num);
    if (v.size() >=2){
        for (decltype(v.size()) i = 0; i != v.size() - 1; ++i)
            cout << v[i] + v[i + 1] << " ";
        cout << endl;
        decltype(v.size()) total = (v.size() % 2 == 0) ? (v.size() / 2) : (v.size() / 2 + 1);
        for (decltype(v.size()) i = 0; i != total; ++i)
            cout << v[i] + v[v.size() - 1 - i] << " ";
        cout << endl;
    }
    
    return 0;
}
