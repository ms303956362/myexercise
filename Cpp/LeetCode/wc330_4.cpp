#include "usual.h"

using ll = long long;

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>> left_l(n, vector<ll>(n + 1)), right_g(n, vector<ll>(n + 1));
        for (int i = 1; i < n; ++i) {
            left_l[i] = left_l[i - 1];
            for (int j = nums[i - 1] + 1; j <= n; ++j) {
                ++left_l[i][j];
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            right_g[i] = right_g[i + 1];
            for (int j = 0; j < nums[i + 1]; ++j) {
                ++right_g[i][j];
            }
        }
        ll ans = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (nums[j] > nums[k]) {
                    ans += left_l[j][nums[k]] * right_g[k][nums[j]];
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{1,3,2,4,5};
    cout << Solution().countQuadruplets(a) << endl;
    return 0;
}
