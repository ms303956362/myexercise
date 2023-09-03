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

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    ll n;
    cin >> n;
    ll m = s.size();
    for (int i = m; i < 61; ++i) {
        s.push_back('0');
        ++m;
    }
    auto all_one = [&]() {
        string tmp = s;
        for (int i = 0; i < 61; ++i) {
            if (tmp[i] == '?') {
                tmp[i] = '1';
            }
        }
        reverse(tmp.begin(), tmp.end());
        ll ret = 0;
        for (int i = 0; i < 61; ++i) {
            if (tmp[i] == '1') {
                ret = ret * 2 + 1;
            } else {
                ret *= 2;
            }
        }
        return ret <= n ? ret : -1;
    };
    ll ans = all_one();
    if (ans != -1) {
        cout << ans << '\n';
        return 0;
    }
    auto split = [&](int k) {
        string tmp = s;
        for (int i = m - 1; i > k; --i) {
            if (tmp[i] == '?') {
                if (n & (1LL << i)) {
                    tmp[i] = '1';
                } else {
                    tmp[i] = '0';
                }
            }
        }
        tmp[k] = '0';
        for (int i = k - 1; i >= 0; --i) {
            if (tmp[i] == '?') {
                tmp[i] = '1';
            }
        }
        reverse(tmp.begin(), tmp.end());
        ll ret = 0;
        for (int i = 0; i < 61; ++i) {
            if (tmp[i] == '1') {
                ret = ret * 2 + 1;
            } else {
                ret *= 2;
            }
        }
        return ret <= n ? ret : -1;
    };
    for (int i = 0; i < m; ++i) {
        if (s[i] == '?') {
            ans = max(ans, split(i));
        }
    }
    cout << ans << '\n';
    return 0;
}
