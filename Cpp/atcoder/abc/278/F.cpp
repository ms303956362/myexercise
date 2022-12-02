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
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    function<void(int, int)> dfs = [&](int j, int s) {
        if (dp[j][s] != -1) {
            return;
        }
        dp[j][s] = 0;
        if (s == (1 << n) - 1) {
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (s & (1 << i)) {
                continue;
            }
            if ((s == 0 || strs[j].back() == strs[i].front())) {
                dfs(i, s | (1 << i));
                if (!dp[i][s | (1 << i)]) {
                    dp[j][s] = 1;
                    break;
                }
            }
        }
    };
    dfs(0, 0);
    cout << (dp[0][0] ? "First" : "Second") << endl;
    return 0;
}
