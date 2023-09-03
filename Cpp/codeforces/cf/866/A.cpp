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
    if (s.size() == 1 && s == "^") {
        cout << 1 << '\n';
        return;
    }
    int i = 0, n = s.size(), ans = 0;
    while (i < n && s[i] == '_') {
        ++i;
        ++ans;
    }
    while (i < n) {
        while (i < n && s[i] == '^') {
            ++i;
        }
        if (i < n) {
            int cnt = 0;
            while (i < n && s[i] == '_') {
                ++i;
                ++cnt;
            }
            ans += cnt - 1;
        }
    }
    if (s[n - 1] == '_') {
        ++ans;
    }
    cout << ans << '\n';
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
