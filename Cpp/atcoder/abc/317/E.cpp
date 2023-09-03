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
#include <numeric>
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
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    unordered_map<char, pair<int, int>> dirs{
        {'>', {0, 1}},
        {'<', {0, -1}},
        {'^', {-1, 0}},
        {'v', {1, 0}}
    };
    int xs = 0, ys = 0, xg = 0, yg = 0;
    vector<pair<int, int>> xp;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (dirs.count(grid[i][j])) {
                xp.emplace_back(i, j);
            } else if (grid[i][j] == 'S') {
                xs = i;
                ys = j;
            } else if (grid[i][j] == 'G') {
                xg = i;
                yg = j;
            }
        }
    }
    auto is_in_field = [&](int x, int y) {
        return 0 <= x && x < m && 0 <= y && y < n;
    };
    for (auto [x, y] : xp) {
        auto [dx, dy] = dirs[grid[x][y]];
        x += dx;
        y += dy;
        while (is_in_field(x, y) && grid[x][y] != '#' && !dirs.count(grid[x][y])) {
            grid[x][y] = '!';
            x += dx;
            y += dy;
        }
    }
    int step = 0;
    vector<vector<bool>> vst(m, vector<bool>(n));
    queue<pair<int, int>> q;
    q.emplace(xs, ys);
    vst[xs][ys] = true;
    while (!q.empty()) {
        int l = q.size();
        while (l--) {
            auto [x, y] = q.front();
            q.pop();
            if (x == xg && y == yg) {
                cout << step << '\n';
                return 0;
            }
            for (const auto& [_, p] : dirs) {
                auto [dx, dy] = p;
                if (is_in_field(x + dx, y + dy) && (grid[x + dx][y + dy] == '.' || grid[x + dx][y + dy] == 'G') && !vst[x + dx][y + dy]) {
                    vst[x + dx][y + dy] = true;
                    q.emplace(x + dx, y + dy);
                }
            }
        }
        ++step;
    }
    cout << -1 << '\n';
    return 0;
}
