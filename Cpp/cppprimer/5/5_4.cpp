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
    vector<int> v1 = {0, 1, 1, 2, 3}, v2 = {0, 1, 1, 2, 3, 5, 8};
    decltype(v1.size()) i, sz;
    if (v1.size() < v2.size())
        sz = v1.size();
    else
        sz = v2.size();
    for (i = 0; i != sz && v1[i] == v2[i]; ++i){

    }
    if (i != sz)
        cout << "false" << endl;
    else
        cout << "true" << endl;
    
    return 0;
}
