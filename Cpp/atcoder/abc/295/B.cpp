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
    int m, n;
    cin >> m >> n;
    vector<vector<char>> ans(m, vector<char>(n, '#'));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == '.') {
                ans[i][j] = '.';
                continue;
            } else if (c == '#') {
                continue;
            }
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    if (abs(x - i) + abs(y - j) <= c - '0') {
                        ans[x][y] = '.';
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}
