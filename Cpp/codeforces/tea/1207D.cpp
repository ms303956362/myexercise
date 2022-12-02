// IO
#include <iostream>
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

pair<int, int> s[300005];
ll fact[300005];
const ll mod = 998244353;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i].first;
        cin >> s[i].second;
    }
    sort(s, s + n);
    bool both = true;
    fact[0] = 1;
    for (int i = 0; i < n; ++i) {
        fact[i + 1] = (fact[i] * (i + 1)) % mod;
        if (i > 0 && s[i].second < s[i - 1].second) {
            both = false;
        }
    }
    ll ans = fact[n], cnt1 = 1, cnt2 = 1, cnt3 = 1;
    int i = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && s[j].first == s[i].first) {
            ++j;
        }
        cnt1 = (cnt1 * fact[j - i]) % mod;
        i = j;
    }
    sort(s, s + n, [&](const auto& lp, const auto& rp) { return lp.second < rp.second || (lp.second == rp.second && lp.first < rp.first); });
    i = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && s[j].second == s[i].second) {
            ++j;
        }
        cnt2 = (cnt2 * fact[j - i]) % mod;
        i = j;
    }
    if (both) {
        i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && s[j].second == s[i].second && s[j].first == s[i].first) {
                ++j;
            }
            cnt3 = (cnt3 * fact[j - i]) % mod;
            i = j;
        }
    }
    // cout << ans << " " << cnt1 << " " << cnt2 << " " << cnt3 << " " << both << endl;
    ans = ((ans - cnt1 - cnt2 + both * cnt3) % mod + mod) % mod;
    cout << ans << endl;
    return 0;
}
