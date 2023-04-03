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

ll dp[505][3005];
ll a[505];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int s = 0; s < (1 << (2 * d + 1)); ++s) {
            for (int k = max(i - d, 0); k <= min(i + d, n - 1); ++k) {
                int j = k - i + d;
            }
        }
    }
    return 0;
}
