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

void rotate(vector<string>& grid) {
    for (int i = 0; i < 2; ++i) {
        for (int j = i; j < 3 - i; ++j) {
            char tmp = grid[i][j];
            grid[i][j] = grid[3 - j][i];
            grid[3 - j][i] = grid[3 - i][3 - j];
            grid[3 - i][3 - j] = grid[j][3 - i];
            grid[j][3 - i] = tmp;
        }
    }
}

void translate(vector<string>& grid, vector<vector<string>>& res) {
    int x = 4, y = 4, a = 0, b = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] == '#') {
                x = min(x, i);
                a = max(a, i);
                y = min(y, j);
                b = max(b, j);
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int c = i + a - x, d = j + b - y;
            if (c >= 4 || d >= 4) {
                continue;
            }
            vector<string> g(4, string(4, '.'));
            for (int s = 0; s < 4; ++s) {
                for (int t = 0; t < 4; ++t) {
                    if (0 <= s + x - i && s + x - i < 4 && 0 <= t + y - j && t + y - j < 4 && grid[s + x - i][t + y - j] == '#') {
                        g[s][t] = '#';
                    }
                }
            }
            res.push_back(g);
        }
    }
}


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<vector<string>>> grids(3);
    for (int i = 0; i < 3; ++i) {
        vector<string> grid(4);
        for (int j = 0; j < 4; ++j) {
            cin >> grid[j];
        }
        for (int j = 0; j < 4; ++j) {
            translate(grid, grids[i]);
            rotate(grid);
        }
    }
    auto check1 = [](vector<string>& g0, vector<string>& g1, vector<string>& g2) {
        vector<vector<int>> cnt(4, vector<int>(4));
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (g0[i][j] == '#') {
                    ++cnt[i][j];
                }
                if (g1[i][j] == '#') {
                    ++cnt[i][j];
                }
                if (g2[i][j] == '#') {
                    ++cnt[i][j];
                }
                if (cnt[i][j] != 1) {
                    return false;
                }
            }
        }
        return true;
    };
    auto check = [&]() {
        for (auto& g0 : grids[0]) {
            for (auto& g1 : grids[1]) {
                for (auto& g2 : grids[2]) {
                    if (check1(g0, g1, g2)) {
                        return true;
                    }
                }
            }
        }
        return false;
    };
    cout << (check() ? "Yes" : "No") << '\n';
    return 0;
}
