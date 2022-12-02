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
const ll mod = 998244353;

class DSU {
    int n;
    vector<int> p;  // 祖先
    vector<int> r;  // 树高 
public:
    DSU(int _n) : n(_n), p(_n), r(_n, 0) {
        for (int i = 0; i != n; ++i) {
            p[i] = i;
        }
    }

    int find(int x) {
        if (p[x] == x)
            return x;
        return p[x] = find(p[x]); // x的祖先直接设为根节点，路径压缩
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py)
            return false;
        if (r[px] < r[py])  // 低树的作为高树的子树，高树高度不变
            p[px] = py;
        else {
            p[py] = px;
            if (r[px] == r[py])   // 树高相等，默认px为py祖先，且需px高度加1
                r[px]++;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, K;
    cin >> n >> K;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    auto check_row = [&](int x, int y) {
        for (int j = 0; j < n; ++j) {
            if (a[x][j] + a[y][j] > K) {
                return false;
            }
        }
        return true;
    };
    auto check_col = [&](int x, int y) {
        for (int i = 0; i < n; ++i) {
            if (a[i][x] + a[i][y] > K) {
                return false;
            }
        }
        return true;
    };
    DSU dr(n + 1), dc(n + 1);
    for (int x = 0; x < n; ++x) {
        for (int y = x + 1; y < n; ++y) {
            if (check_col(x, y)) {
                dc.unite(x, y);
            }
            if (check_row(x, y)) {
                dr.unite(x, y);
            }
        }
    }
    vector<ll> f(n + 1, 1), cntr(n + 1), cntc(n + 1);
    for (int i = 1; i <= n; ++i) {
        f[i] = (f[i - 1] * i) % mod;
        ++cntr[dr.find(i - 1)];
        ++cntc[dc.find(i - 1)];
    }
    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        ans = (ans * f[cntr[i]] % mod * f[cntc[i]]) % mod;
    }
    cout << ans << endl;
    return 0;
}
