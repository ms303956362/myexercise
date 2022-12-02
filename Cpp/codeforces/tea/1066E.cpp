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

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<long long> cnt(n);
    for (int i = m - 1, c = 0; i >= 0; --i) {
        c += b[i] - '0';
        if (i < n) {
            cnt[i] = c;
        }
    }
    long long ans = 0, mod = 998244353, num = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1') {
            // cout << num << " " << cnt[i] << endl;
            ans = (ans + cnt[i] * num % mod) % mod;
        }
        num = (num * 2) % mod;
    }
    cout << ans << endl;
    return 0;
}
