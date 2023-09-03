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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    int n = min(h, w);
    auto is_valid = [&](int i, int j) {
        return 0 <= i && i < h && 0 <= j && j < w && grid[i][j] == '#';
    };
    vector<int> ans(n);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] != '#') {
                continue;
            }
            int cnt = -1;
            for (int k = 1; k <= n && is_valid(i + k, j + k) && is_valid(i + k, j - k) && is_valid(i - k, j + k) && is_valid(i - k, j - k); ++k) {
                ++cnt;
            }
            if (cnt >= 0) {
                ++ans[cnt];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
