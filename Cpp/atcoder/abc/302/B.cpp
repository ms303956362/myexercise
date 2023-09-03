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
    vector<string> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
    string target("snuke");
    bool ok = true;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (const auto& [dx, dy] : dirs) {
                int x = i, y = j;
                ok = true;
                for (int k = 0; k < 5; ++k) {
                    if (0 <= x && x < m && 0 <= y && y < n && a[x][y] == target[k]) {
                        x += dx;
                        y += dy;
                    } else {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    int x = i, y = j;
                    for (int k = 0; k < 5; ++k) {
                        cout << x + 1 << ' ' << y + 1 << '\n';
                        x += dx;
                        y += dy;
                    }
                }
            }
            if (ok) {
                break;
            }
        }
        if (ok) {
            break;
        }
    }
    return 0;
}
