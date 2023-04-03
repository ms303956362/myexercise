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
    int n, q;
    cin >> n >> q;
    vector<int> p(n, -1), d(n);
    for (int i = 1 ; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        p[i] = x;
        ++d[i];
        ++d[x];
    }
    vector<bool> has(n);
    for (int i = 0; i < q; ++i) {
        int m;
        cin >> m;
        vector<int> v;
        int ans = 0;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            --x;
            ans += d[x];
            v.emplace_back(x);
            has[x] = true;
        }
        for (const auto& x : v) {
            if (p[x] != -1 && has[p[x]]) {
                ans -= 2;
            }
        }
        if (has[0]) {
            ++ans;
        }
        cout << ans << '\n';
        for (const auto& x : v) {
            has[x] = false;
        }
    }
    return 0;
}
