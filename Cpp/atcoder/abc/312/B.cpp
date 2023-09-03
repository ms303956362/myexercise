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
    int n, m;
    cin >> n >> m;
    vector<string> grid(n, string(m, '.'));
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    auto check = [&](int i, int j) {
        int is = i, ie = i + 9, js = j, je = j + 9;
        for (int a = is; a < is + 3; ++a) {
            for (int b = js; b < js + 3; ++b) {
                if (grid[a][b] != '#') {
                    return false;
                }
            }
        }
        for (int a = ie - 3; a < ie; ++a) {
            for (int b = je - 3; b < je; ++b) {
                if (grid[a][b] != '#') {
                    return false;
                }
            }
        }
        for (int a = is; a <= is + 3; ++a) {
            if (grid[a][js + 3] != '.') {
                return false;
            }
        }
        for (int b = js; b <= js + 3; ++b) {
            if (grid[is + 3][b] != '.') {
                return false;
            }
        }
        for (int a = ie - 4; a < ie; ++a) {
            if (grid[a][je - 4] != '.') {
                return false;
            }
        }
        for (int b = je - 4; b < je; ++b) {
            if (grid[ie - 4][b] != '.') {
                return false;
            }
        }
        return true;
    };
    for (int i = 0; i <= n - 9; ++i) {
        for (int j = 0; j <= m - 9; ++j) {
            if (check(i, j)) {
                cout << i + 1 << ' ' << j + 1 << '\n';
            }
        }
    }
    return 0;
}
