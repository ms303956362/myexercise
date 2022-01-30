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
    vector<long long> nums;
    for (long long i = 0; i < 4; ++i) {
        long long a = 0;
        cin >> a;
        nums.push_back(a);
    }
    string ops;
    for (long long i = 0; i < 3; ++i) {
        char c;
        cin >> c;
        ops.push_back(c);
    }
    vector<long long> curr;
    long long ans = 0x3f3f3f3f3f3f3f3f;
    function<void(vector<long long>, long long)> backtrack = [&](vector<long long> a, long long t) {
        if (t == 3) {
            ans = min(ans, a[0]);
            return;
        }
        long long n = a.size();
        for (long long i = 0; i < n; ++i) {
            for (long long j = i + 1; j < n; ++j) {
                vector<long long> b;
                if (ops[t] == '+') {
                    b.push_back(a[i] + a[j]);
                } else {
                    b.push_back(a[i] * a[j]);
                }
                for (long long k = 0; k < n; ++k) {
                    if (k != i && k != j) {
                        b.push_back(a[k]);
                    }
                }
                backtrack(b, t + 1);
            }
        }
    };
    backtrack(nums, 0);
    cout << ans << endl;
    return 0;
}
