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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using ll = long long;
ll a[5005], pre[5005];
ll dp[5005][5005];

int main(int argc, char const *argv[])
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        pre[i] = pre[i + 1] + a[i];
    }
    for (int i = 1; i <= k; ++i) {
        dp[n][i] = (ll)(-1e9) * (ll)(1e9);
    }
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for (int i = n - m; i >= 0; --i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = dp[i + 1][j];
            if (i + m <= n) {
                dp[i][j] = max(dp[i][j], dp[i + m][j - 1] + pre[i] - pre[i + m]);
            }
        }
    }
    cout << dp[0][k] << endl;
    return 0;
}
