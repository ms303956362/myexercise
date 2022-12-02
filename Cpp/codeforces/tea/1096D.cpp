// IO
#include <iostream>
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

ll a[100005];
ll dp[100005][4];

int main(int argc, char const *argv[])
{
    int n;
    string s;
    cin >> n >> s;
    memset(a, 0, sizeof(ll) * n);
    memset(dp, 0, sizeof(ll) * n * 4);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    char ch[4] = {'h', 'a', 'r', 'd'};
    if (s[0] == 'h') {
        dp[0][0] = a[0];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (s[i] == ch[j]) {
                if (j == 0) {
                    dp[i][j] = a[i] + dp[i - 1][j];
                } else {
                    dp[i][j] = min(a[i] + dp[i - 1][j], dp[i - 1][j - 1]);
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n - 1][3] << endl;
    return 0;
}
