// IO
#include <iostream>
#include <iomanip>      // std::setprecision
#include <sstream>
// ordered container
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <stack>
#include <queue>
// associative-container
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
// algorithm
#include <algorithm>
#include <cmath>
// utility
#include <initializer_list>
#include <iterator>
#include <memory>
#include <utility>
// c
#include <cstdio>
#include <cstdlib>
#include <cstring>
// functional
#include <functional>

using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(256);
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i]];
    }
    string ans1, ans2;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (cnt[c] > 0) {
            if (ans1.empty() || ans1.back() != c - 1) {
                ans1 += string(cnt[c], c);
                cnt[c] = 0;
            }
        }
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (cnt[c] > 0) {
            ans2 += string(cnt[c], c);
        }
    }
    auto check = [](string s) {
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1] + 1 || s[i] == s[i - 1] - 1) {
                return false;
            }
        }
        return true;
    };
    if (check(ans1 + ans2)) {
        cout << ans1 + ans2 << '\n';
        return;
    }
    if (check(ans2 + ans1)) {
        cout << ans2 + ans1 << '\n';
        return;
    }
    cout << "No answer" << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
