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

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, r, c;
        cin >> n >> k >> r >> c;
        vector<vector<char>> grid(n + 1, vector<char>(n + 1, '.'));
        vector<bool> vst_r(n + 1), vst_c(n + 1);
        queue<pair<int, int>> q;
        auto bfs = [&](int r, int c) {
            q.emplace(r, c);
            grid[r][c] = 'X';
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (!vst_r[x]) {
                    vst_r[x] = true;
                    for (int v = y + k; v <= n; v += k) {
                        grid[x][v] = 'X';
                        q.emplace(x, v);
                    }
                    for (int v = y - k; v >= 1; v -= k) {
                        grid[x][v] = 'X';
                        q.emplace(x, v);
                    }
                }
                if (!vst_c[y]) {
                    vst_c[y] = true;
                    for (int u = x + k; u <= n; u += k) {
                        grid[u][y] = 'X';
                        q.emplace(u, y);
                    }
                    for (int u = x - k; u >= 1; u -= k) {
                        grid[u][y] = 'X';
                        q.emplace(u, y);
                    }
                }
            }
        };
        bfs(r, c);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (!vst_r[i] && !vst_c[j]) {
                    bfs(i, j);
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
