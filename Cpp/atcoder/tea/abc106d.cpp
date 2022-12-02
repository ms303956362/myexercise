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
    int n, m, Q;
    cin >> n >> m >> Q;
    vector<vector<int>> cnt(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        ++cnt[l][r];
    }
    vector<vector<int>> pre(n + 1, vector<int>(n + 2));
    for (int i = 0; i <= n; ++i) {
        for (int j = n; j >= 0; --j) {
            pre[i][j] = pre[i][j + 1] + cnt[i][j];
        }
    }
    for (int i = 0; i < Q; ++i) {
        int p, q;
        cin >> p >> q;
        int ans = 0;
        for (int t = p; t <= q; ++t) {
            ans += pre[t][0] - pre[t][q + 1];
        }
        cout << ans << endl;
    }
    return 0;
}
