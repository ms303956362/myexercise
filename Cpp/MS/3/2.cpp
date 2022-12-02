#include "usual.h"

string solution(string &S) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    vector<int> cnt(10);
    for (const auto& c : S) {
        ++cnt[c - '0'];
    }
    int single_num = -1;
    for (int i = 9; i >= 0; --i) {
        if (cnt[i] % 2 == 1) {
            single_num = i;
            break;
        }
    }
    string half;
    for (int i = 9; i >= 0; --i) {
        if (i == 0 && half.empty()) {
            break;
        }
        for (int j = 0; j < cnt[i] / 2; ++j) {
            half.push_back(i + '0');
        }
    }
    string second_half = half;
    reverse(second_half.begin(), second_half.end());
    if (single_num != -1) {
        half.push_back(single_num + '0');
    }
    if (half.empty()) {
        return "0";
    }
    return half + second_half;
}

int main(int argc, char const *argv[])
{
    string s("900");
    cout << solution(s) << endl;
    return 0;
}
