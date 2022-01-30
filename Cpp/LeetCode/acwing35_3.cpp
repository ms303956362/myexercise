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
    int n;
    cin >> n;
    vector<int> s(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    int ans = 1e9;
    for (int i = 1; i < n - 1; ++i) {
        int c1 = 1e9, c2 = 1e9;
        for (int j = 0; j < i; ++j) {
            if (s[j] < s[i]) {
                c1 = min(c1, c[j]);
            }
        }
        for (int j = n - 1; j > i; --j) {
            if (s[i] < s[j]) {
                c2 = min(c2, c[j]);
            }
        }
        if (c1 != 1e9 && c2 != 1e9) {
            ans = min(ans, c1 + c2 + c[i]);
        }
    }
    if (ans != 1e9)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
