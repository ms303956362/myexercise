#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// int main(int argc, char const *argv[])
// {
//     string s;
//     cin >> s;
//     int n = s.size();
//     if (s[0] == s[n - 1]) {
//         cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
//     } else {
//         // s[0]
//         int t2 = n - 1;
//         while (s[t2] != s[0]) {
//             --t2;
//         }
//         int s1 = 0;
//         while (s[s1] != s[n - 1]) {
//             ++s1;
//         }
//         if (n - 1 - s1 > t2) {
//             cout << s1 + 1 << " " << n - 1 << " " << s1 + 2 << " " << n << endl;
//         } else {
//             cout << 1 << " " << t2 + 1 << " " << 2 << " " << t2 + 2 << endl;
//         }
//     }
//     return 0;
// }

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        cnt[i] = cnt[i + 1] + (s[i] == '1');
    }
    unordered_map<int, int> a;
    int ans = 1, s1 = 0, s2 = 0;
    for (int l = n - 1; l > 0; --l) {
        a.clear();
        for (int i = 0; i + l <= n; ++i) {
            int num = cnt[i] - cnt[i + l];
            if (a.count(num)) {
                ans = l;
                s1 = i;
                s2 = a[num];
                break;
            }
            a[num] = i;
        }
        if (ans > 1) {
            break;
        }
    }
    cout << s1 + 1 << " " << s1 + ans << " " << s2 + 1 << " " << s2 + ans << endl;
    return 0;
}

