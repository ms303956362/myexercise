#include <string>
using std::getline;
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    // 3.2a
    // string s;
    // while (getline(cin, s))
    //     cout << s << endl;
    //3.2b
    // string s;
    // while (cin >> s)
    //     cout << s << endl;

    // 3.4a
    // string s1, s2;
    // getline(cin, s1);
    // getline(cin, s2);
    // if (s1 == s2)
    //     cout << "Two strings are equal" << endl;
    // else{
    //     if (s1 < s2)
    //         s1 = s2;
    //     cout << "Two string aren't equal. \"" << s1 << "\" is greater" << endl;
    // }

    // 3.4b
    // string s1, s2;
    // getline(cin, s1);
    // getline(cin, s2);
    // if (s1.size() == s2.size())
    //     cout << "The size of two strings are equal" << endl;
    // else{
    //     if (s1.size() < s2.size())
    //         s1 = s2;
    //     cout << "The size of two string aren't equal. The size of \"" << s1 << "\" is greater" << endl;
    // }

    // 3.5a
    // string s, s_sum;
    // while (cin >> s){
    //     s_sum += s;
    // }
    // cout << s_sum << endl;

    // 3.5b
    // string s, s_sum;
    // while (cin >> s){
    //     if (s_sum.empty())
    //         s_sum = s;
    //     else
    //         s_sum += " " + s;
    // }
    // cout << s_sum << endl;

    // 3.6
    // string s;
    // while (getline(cin, s)){
    //     for (auto &c : s){
    //         c = 'X';
    //     }
    //     cout << s << endl;
    // }

    // 3.8a
    // string s;
    // while (getline(cin, s)){
    //     decltype(s.size()) i = 0;
    //     while (i < s.size()){
    //         s[i] = 'X';
    //         ++i;
    //     }
    //     cout << s << endl;
    // }

    // 3.8b
    // string s;
    // while (getline(cin, s)){
    //     for (decltype(s.size()) i = 0; i!=s.size();++i){
    //         s[i] = 'X';
    //     }
    //     cout << s << endl;
    // }

    // 3.9
    // string s;
    // cout << s[0] << endl;   //编译可通过，s初始化为空，s[0]为UB

    // 3.10
    // string s;
    // while (getline(cin, s)){
    //     string s_temp;
    //     for (auto c : s)
    //         if (!ispunct(c))
    //             cout << c;
    //     cout << endl;
    // }

    // 3.11
    const string s = "Keep out!";
    for (auto &c:s){
        cout << c;  //OK
        // c = 'X';    //not OK
    }
    return 0;
}
