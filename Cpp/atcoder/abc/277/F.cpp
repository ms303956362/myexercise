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

bool check_intervals(multiset<pair<int, int>>& intervals) {
    int l = intervals.size();
    auto p = intervals.begin();
    for (int i = 0; i < l - 1; ++i) {
        auto q = next(p);
        if (p->second > q->first) {
            return false;
        }
    }
    return true;
}

bool check_cycle(int n, vector<vector<int>>& g) {
    vector<int> vst(n, 0);
    function<bool(int)> dfs = [&](int u) {
        vst[u] = 1;
        for (const auto& v : g[u]) {
            if (vst[v] == 1) {
                return false;
            } else if (vst[v] == 0 && !dfs(v)) {
                return false;
            }
        }
        vst[u] = 2;
        return true;
    };
    for (int i = 0; i < n; ++i) {
        if (!vst[i] && !dfs(i)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    multiset<pair<int, int>> intervals;
    vector<vector<int>> a(m, vector<int>(n));
    vector<vector<pair<int, int>>> aj(m);
    for (int i = 0; i < m; ++i) {
        int max_num = -1, min_num = 0x3f3f3f3f;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (x != 0) {
                max_num = max(max_num, x);
                min_num = min(min_num, x);
            }
            a[i][j] = x;
            aj[i].emplace_back(x, j);
        }
        if (max_num != -1) {
            intervals.emplace(min_num, max_num);
        }
    }
    if (!check_intervals(intervals)) {
        cout << "No" << endl;
        return 0;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        sort(aj[i].begin(), aj[i].end());
        int j = n - 1;
        while (j > 0 && aj[i][j - 1].first > 0) {
            int k = j - 1;
            while (k >= 0 && aj[i][k].first == aj[i][j].first) {
                --k;
            }
            if (k < 0 || aj[i][k].first == 0) {
                break;
            }
            while (j > k) {
                g[aj[i][j].second].push_back(aj[i][k].second);
                --j;
            }
        }
        // for (int j = n - 1; j > 0 && aj[i][j - 1].first > 0; --j) {
        //     if (aj[i][j].first > aj[i][j - 1].first) {
        //         g[aj[i][j].second].push_back(aj[i][j - 1].second);
        //     }
        // }
    }
    cout << (check_cycle(n, g) ? "Yes" : "No") << endl;
    return 0;
}
