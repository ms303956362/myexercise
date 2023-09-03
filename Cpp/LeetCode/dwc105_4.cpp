#include "usual.h"

// class Solution {
// public:
//     bool canTraverseAllPairs(vector<int>& nums) {
//         int n = nums.size(), mx = *max_element(nums.begin(), nums.end());
//         vector<bool> has(mx + 1);
//         auto check_factors = [&](int num) {
//             if (has[num]) {
//                 return true;
//             }
//             for (int i = 2; i * i <= num; ++i) {
//                 if (num % i == 0) {
//                     if (has[i] || has[num / i]) {
//                         return true;
//                     }
//                 }
//             }
//             return false;
//         };
//         auto fill_factors = [&](int num) {
//             has[num] = true;
//             for (int i = 2; i * i <= num; ++i) {
//                 if (num % i == 0) {
//                     has[i] = true;
//                     if (i * i != num) {
//                         has[num / i] = true;
//                     }
//                 }
//             }
//         };
//         if (nums[n - 1] == 1) {
//             return false;
//         }
//         has[nums[n - 1]] = true;
//         fill_factors(nums[n - 1]);
//         for (int i = n - 2; i >= 0; --i) {
//             if (nums[i] == 1) {
//                 return false;
//             }
//             if (!check_factors(nums[i])) {
//                 return false;
//             }
//             fill_factors(nums[i]);
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end());
        int sz = n;
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            return p[x] == x ? x : (p[x] = find(p[x]));
        };
        auto merge = [&](int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) {
                return;
            }
            p[px] = py;
            --sz;
        };
        vector<vector<int>> idx(mx + 1);
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            idx[num].push_back(i);
            for (int k = 2; k * k <= num; ++k) {
                if (num % k == 0) {
                    idx[k].push_back(i);
                    if (k * k != num) {
                        idx[num / k].push_back(i);
                    }
                }
            }
        }
        for (int i = 2; i <= mx; ++i) {
            int l = idx[i].size();
            for (int k = 0; k < l - 1; ++k) {
                merge(idx[i][k], idx[i][k + 1]);
            }
        }
        return sz == 1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{21,88,75};
    Solution().canTraverseAllPairs(a);
    return 0;
}
