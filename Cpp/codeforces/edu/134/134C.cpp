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

using namespace std;

int a[200005], b[200005], d_min[200005], d_max[200005];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int i = 0, j = 0;
    while (i < n) {
        while (j < n && b[j] < a[i]) {
            ++j;
        }
        d_min[i] = b[j] - a[i];
        ++i;
    }
    d_max[n - 1] = b[n - 1] - a[n - 1];
    i = n - 2, j = n - 1;
    while (i >= 0) {
        if (a[i + 1] > b[i]) {
            j = i;
        }
        d_max[i] = b[j] - a[i];
        --i;
    }
    for (int i = 0; i < n; ++i) {
        cout << d_min[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << d_max[i] << " ";
    }
    cout << endl;
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
