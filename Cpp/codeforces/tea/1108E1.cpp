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


int a[305], l[305], r[305];

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i];
        --l[i];
        --r[i];
    }
    int max_diff = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                continue;
            }
            vector<int> curr;
            int diff = a[j] - a[i];
            for (int k = 0; k < m; ++k) {
                if (l[k] <= i && i <= r[k] && !(l[k] <= j && j <= r[k])) {
                    ++diff;
                    curr.push_back(k);
                }
            }
            if (diff > max_diff) {
                max_diff = diff;
                ans = curr;
            }
        }
    }
    cout << max_diff << endl;
    cout << ans.size() << endl;
    for (const auto& k : ans) {
        cout << k + 1 << " ";
    }
    cout << endl;
    return 0;
}
