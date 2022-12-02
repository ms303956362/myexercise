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

int a[105], b[105], ans[105][105];

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    auto check = [&]() {
        for (int k = 0; k < 32; ++k) {
            int cnt_row = 0, cnt_col = 0;
            for (int i = 0; i < n; ++i) {
                cnt_row += ((a[i] >> k) & 1);
            }
            for (int i = 0; i < m; ++i) {
                cnt_col += ((b[i] >> k) & 1);
            }
            if (cnt_row % 2 != cnt_col % 2) {
                return false;
            }
            if (cnt_row > cnt_col) {
                int i = 0, j = 0;
                while (j < m) {
                    if ((b[j] >> k) & 1) {
                        while (i < n && ((a[i] >> k) & 1) == 0) {
                            ++i;
                        }
                        ans[i][j] |= (1 << k);
                        ++i;
                    }
                    ++j;
                }
                while (i < n) {
                    if ((a[i] >> k) & 1) {
                        ans[i][0] |= (1 << k);
                    }
                    ++i;
                }
            } else {
                int i = 0, j = 0;
                while (i < n) {
                    if ((a[i] >> k) & 1) {
                        while (j < m && ((b[j] >> k) & 1) == 0) {
                            ++j;
                        }
                        ans[i][j] |= (1 << k);
                        ++j;
                    }
                    ++i;
                }
                while (j < m) {
                    if ((b[j] >> k) & 1) {
                        ans[0][j] |= (1 << k);
                    }
                    ++j;
                }
            }
        }
        return true;
    };
    if (check()) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
