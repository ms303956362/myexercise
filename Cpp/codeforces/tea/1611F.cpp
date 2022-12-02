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

ll a[200005];

void solve() {
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll curr = s;
    int i = 0, j = 0, max_len = 0, max_i = 0, max_j = 0;
    while (i < n) {
        curr += a[i];
        while (j <= i && curr < 0) {
            curr -= a[j];
            ++j;
        }
        // cout << i << ": " << j << endl;
        if (i - j + 1 > max_len) {
            max_len = i - j + 1;
            max_i = i;
            max_j = j;
        }
        ++i;
    }
    if (max_len == 0) {
        cout << -1 << endl;
    } else {
        cout << max_j + 1 << " " << max_i + 1 << endl;
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
