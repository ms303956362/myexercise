#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
    // 5.14
    // string s, s_prev, max_s;
    // unsigned int times = 0, max_times = 0;
    // while (cin >> s){
    //     if (s == s_prev){
    //         ++times;
    //     } else {
    //         s_prev = s;
    //         times = 1;
    //     }
    //     if (times > max_times){
    //         max_s = s;
    //         max_times = times;
    //     }
    // }
    // cout << "Word depulicating for the largest times: " << max_s << ", max times: " << max_times;

    // 5.17
    // vector<int> v1 = {0, 1, 1, 2, 3}, v2 = {0, 1, 1, 2, 3, 5, 8};
    // decltype(v1.size()) i, sz;
    // if (v1.size() < v2.size())
    //     sz = v1.size();
    // else
    //     sz = v2.size();
    // for (i = 0; i != sz && v1[i] == v2[i]; ++i){

    // }
    // if (i != sz)
    //     cout << "false" << endl;
    // else
    //     cout << "true" << endl;
    
    // 5.19
    // string s1, s2, rsp;
    // do{
    //     cout << "Enter two strings: " << endl;
    //     cin >> s1 >> s2;
    //     cout << "The shorter one is " << (s1.size() < s2.size() ? s1 : s2) << endl;
    //     cout << "Continue?[y]/[n]" << endl;
    //     cin >> rsp;
    // } while (!rsp.empty() && rsp[0] != 'n');

    // 5.20
    // string s, s_prev;
    // while (cin >> s){
    //     if (s == s_prev)
    //         break;
    //     s_prev = s;
    // }
    // if (cin.eof())
    //     cout << "no duplicated word" << endl;
    // else
    //     cout << "duplicated word: " << s << endl;
        
    // 5.21
    // string s, s_prev;
    // while (cin >> s){
    //     if (s == s_prev){
    //         if (s[0] >= 65 && s[0] <= 90)
    //             break;
    //         else
    //             continue;
    //     }
    //     s_prev = s;
    // }
    // if (cin.eof())
    //     cout << "no duplicated word" << endl;
    // else
    //     cout << "duplicated word: " << s << endl;

    // 5.23
    int a, b;
    while (cin >> a >> b)
    {
        try{
            if (b == 0)
                throw runtime_error("A number can't be divided by zero");
            else
                cout << a << "/" << b << "=" << a / b << endl;
        } catch(runtime_error &err){
            cout << err.what() << endl;
            cout << "retry?[y]/[n]" << endl;
            char ch;
            cin >> ch;
            if (!cin || ch=='n')
                break;
        }
    }

    return 0;
}
