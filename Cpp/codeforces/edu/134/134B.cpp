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

bool check1(int n, int m, int sx, int sy, int d) {
    for (int x = 1; x <= n; ++x) {
        if (abs(x - sx) + abs(1 - sy) <= d) {
            return false;
        }
    }
    for (int y = 1; y <= m; ++y) {
        if (abs(n - sx) + abs(y - sy) <= d) {
            return false;
        }
    }
    return true;
}

bool check2(int n, int m, int sx, int sy, int d) {
    for (int y = 1; y <= m; ++y) {
        if (abs(1 - sx) + abs(y - sy) <= d) {
            return false;
        }
    }
    for (int x = 1; x <= n; ++x) {
        if (abs(x - sx) + abs(m - sy) <= d) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;
    if (check1(n, m, sx, sy, d) || check2(n, m, sx, sy, d)) {
        cout << n + m - 2 << endl;
    } else {
        cout << -1 << endl;
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
