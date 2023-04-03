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

bool dp[55][10005];
int a[55], b[55];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    dp[n][0] = true;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= x; ++j) {
            dp[i][j] = dp[i + 1][j];
            for (int k = 0; k <= b[i] && k * a[i] <= j && !dp[i][j]; ++k) {
                dp[i][j] |= dp[i + 1][j - k * a[i]];
            }
        }
    }
    cout << (dp[0][x] ? "Yes" : "No") << endl;
    return 0;
}
