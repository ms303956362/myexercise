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
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<vector<int>> diff(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int k = 0; k < m; ++k) {
                if (v[i][k] != v[j][k]) {
                    ++cnt;
                }
            }
            diff[i][j] = cnt;
        }
    }
    vector<bool> vst(n);
    vector<int> order;
    function<bool(int)> backtrack = [&](int i) {
        if (i == n) {
            for (int j = 0; j < n - 1; ++j) {
                if (diff[order[j]][order[j + 1]] != 1) {
                    return false;
                }
            }
            return true;
        }
        for (int j = 0; j < n; ++j) {
            if (!vst[j]) {
                vst[j] = true;
                order.push_back(j);
                if (backtrack(i + 1)) {
                    return true;
                }
                order.pop_back();
                vst[j] = false;
            }
        }
        return false;
    };
    cout << (backtrack(0) ? "Yes" : "No") << '\n';
    return 0;
}
