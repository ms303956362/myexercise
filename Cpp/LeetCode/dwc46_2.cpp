#include "usual.h"

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0, n = nums.size();
        for (const auto& v : groups) {
            bool ok = false;
            int m = v.size();
            while (i < n && !ok) {
                while (i < n && v[0] != nums[i]) {
                    ++i;
                }
                int j = i, k = 0;
                for (; j < n && k < m; ++j, ++k) {
                    if (nums[j] != v[k])
                        break;
                }
                if (k == m) {
                    ok = true;
                    i = j;
                } else
                    ++i;
            }
            if (i >= n && !ok)
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v1{{1, -1, -1}, {3, -2, 0}};
    vector<int> v2{1, -1, 0, 1, -1, -1, 3, -2, 0};
    Solution().canChoose(v1, v2);
    return 0;
}
