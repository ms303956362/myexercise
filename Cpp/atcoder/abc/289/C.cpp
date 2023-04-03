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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        a[i] = vector<int>(c);
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int s = 1; s < (1 << m); ++s) {
        vector<bool> has(n + 1);
        for (int i = 0; i < m; ++i) {
            if (s & (1 << i)) {
                for (const auto& num : a[i]) {
                    has[num] = true;
                }
            }
        }
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            if (!has[i]) {
                ok = false;
                break;
            }
        }
        ans += ok;
    }
    cout << ans << '\n';
    return 0;
}
