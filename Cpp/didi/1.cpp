/**
n: 9
0: 2
1: 1
2: 1
x0 + x1 + x2 == n
abs(x1 - x2) % 3 == 0
?12?0?9??
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int n = s.size();
    int total = n;
    vector<int> cnt(3);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            continue;
        }
        --total;
        ++cnt[(s[i] - '0') % 3];
    }
    auto check = [&](int i, char c) {
        if (i > 0 && s[i - 1] == c) {
            return false;
        }
        if (i < n - 1 && s[i + 1] == c) {
            return false;
        }
        return true;
    };
    int i = 0;
    for (; i < n; ++i) {
        if (s[i] != '?') {
            continue;
        }
        if (total == 1) {
            break;
        }
        for (char c = '0'; c <= '9'; ++c) {
            if (i == 0 && c == '0') {
                continue;
            }
            if (check(i, c)) {
                s[i] = c;
                ++cnt[(c - '0') % 3];
                --total;
                break;
            }
        }
    }
    if (abs(cnt[1] % 3 - cnt[2] % 3) % 3 == 0) {
        for (char c = '0'; c <= '9'; c += 3) {
            if (i == 0 && c == '0') {
                continue;
            }
            if (check(i, c)) {
                s[i] = c;
                break;
            }
        }
    } else if (abs(cnt[1] % 3 - cnt[2] % 3) % 3 == 1) {
        // 1010102
        // 21212
        if (cnt[1] % 3 > cnt[2] % 3) {
            for (char c = '2'; c <= '9'; c += 3) {
                if (check(i, c)) {
                    s[i] = c;
                    break;
                }
            }
        } else {
            for (char c = '1'; c <= '9'; c += 3) {
                if (check(i, c)) {
                    s[i] = c;
                    break;
                }
            }
        }
    } else {
        // 202020101
        if (cnt[1] % 3 > cnt[2] % 3) {
            for (char c = '1'; c <= '9'; c += 3) {
                if (check(i, c)) {
                    s[i] = c;
                    break;
                }
            }
        } else {
            for (char c = '2'; c <= '9'; c += 3) {
                if (check(i, c)) {
                    s[i] = c;
                    break;
                }
            }
        }
    }
    cout << s << endl;
    return 0;
}
