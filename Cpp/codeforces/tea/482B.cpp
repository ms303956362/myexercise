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

int diff[100005][32], a[100005], pre[32], pre_sum[100005][32];
int l[100005], r[100005], q[100005];

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int left, right, query;
        cin >> left >> right >> query;
        l[i] = left - 1;
        r[i] = right - 1;
        q[i] = query;
        for (int j = 0; j < 32; ++j) {
            if (query & (1 << j)) {
                ++diff[left - 1][j];
                --diff[right][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 32; ++j) {
            pre[j] += diff[i][j];
            if (pre[j] > 0) {
                a[i] |= (1 << j);
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 32; ++j) {
            pre_sum[i][j] = pre_sum[i + 1][j] + ((a[i] & (1 << j)) > 0);
        }
    }
    auto check = [&]() {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < 32; ++j) {
                if (q[i] & (1 << j)) {
                    if (pre_sum[l[i]][j] - pre_sum[r[i] + 1][j] == 0) {
                        return false;
                    }
                } else {
                    if (pre_sum[l[i]][j] - pre_sum[r[i] + 1][j]  == r[i] - l[i] + 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    };
    if (check()) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
