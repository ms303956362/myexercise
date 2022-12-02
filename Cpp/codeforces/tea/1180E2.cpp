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

int a[100005], left_max[100005], right_max[100005];

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int max_elem = INT_MIN, min_elem = INT_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_elem = max(max_elem, a[i]);
        min_elem = min(min_elem, a[i]);
    }
    vector<tuple<int, int, int>> left_intervals, right_intervals;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        left_intervals.emplace_back(l, r, i);
        right_intervals.emplace_back(l, r, i);
    }
    left_max[0] = 0xff3f3f3f;
    for (int i = 1; i < n; ++i) {
        left_max[i] = max(left_max[i - 1], a[i - 1]);
    }
    right_max[n - 1] = 0xff3f3f3f;
    for (int i = n - 2; i >= 0; --i) {
        right_max[i] = max(right_max[i + 1], a[i + 1]);
    }
    sort(left_intervals.begin(), left_intervals.end(), [&](const tuple<int, int, int>& lp, const tuple<int, int, int>& rp) {
        return get<0>(lp) < get<0>(rp);
    });
    sort(right_intervals.begin(), right_intervals.end(), [&](const tuple<int, int, int>& lp, const tuple<int, int, int>& rp) {
        return get<1>(lp) > get<1>(rp);
    });
    vector<int> ans;
    int max_diff = max_elem - min_elem, max_i = -1, max_j = -1, max_dir = -1;
    for (int i = 1; i < n; ++i) {
        int total = 0;
        for (int j = 0; j < m; ++j) {
            auto [l, r, idx] = left_intervals[j];
            if (l <= i && i <= r) {
                ++total;
            }
        }
        for (int j = 0; j < m; ++j) {
            auto [l, r, idx] = left_intervals[j];
            if (l <= i && i <= r) {
                int diff = left_max[l] - a[i] + total;
                if (diff > max_diff) {
                    max_diff = diff;
                    max_i = i;
                    max_j = j;
                    max_dir = 0;
                }
                --total;
            }
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int total = 0;
        for (int j = 0; j < m; ++j) {
            auto [l, r, idx] = right_intervals[j];
            if (l <= i && i <= r) {
                ++total;
            }
        }
        for (int j = 0; j < m; ++j) {
            auto [l, r, idx] = right_intervals[j];
            if (l <= i && i <= r) {
                int diff = right_max[r] - a[i] + total;
                if (diff > max_diff) {
                    max_diff = diff;
                    max_i = i;
                    max_j = j;
                    max_dir = 1;
                }
                --total;
            }
        }
    }
    cout << max_diff << endl;
    // printf("%d %d %d %d\n", max_diff, max_i, max_j, max_dir);
    if (max_i != -1) {
        vector<int> indices;
        if (max_dir == 0) {
            for (int j = 0; j < m; ++j) {
                auto [l, r, idx] = left_intervals[j];
                if (l <= max_i && max_i <= r && j >= max_j) {
                    indices.push_back(idx);
                }
            }
        } else {
            for (int j = 0; j < m; ++j) {
                auto [l, r, idx] = right_intervals[j];
                if (l <= max_i && max_i <= r && j >= max_j) {
                    indices.push_back(idx);
                }
            }
        }
        cout << indices.size() << endl;
        for (const auto& i : indices) {
            cout << i + 1 << " ";
        }
    } else {
        cout << 0 << endl;
    }
    cout << endl;
    return 0;
}
