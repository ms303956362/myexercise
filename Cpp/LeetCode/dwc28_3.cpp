#include "usual.h"

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> pre_len(n + 1, -1), beg(n + 1, -1), pre_len_min(n + 1, -1);
        unordered_map<int, int> mp;
        int sum = 0;
        ++n;
        mp[0] = 0;
        for (int i = 1; i != n; ++i) {
            sum += arr[i - 1];
            mp[sum] = i;
            auto p = mp.find(sum - target);
            if (p != mp.end()) {
                pre_len[i] = i - p->second;
                beg[i] = p->second;
                if (pre_len_min[i - 1] == -1 || pre_len[i] < pre_len_min[i - 1])
                    pre_len_min[i] = pre_len[i];
                else
                    pre_len_min[i] = pre_len_min[i - 1];
            } else {
                pre_len_min[i] = pre_len_min[i - 1];
            }
        }
        int min_len = INT_MAX;
        for (int i = 1; i != n; ++i) {
            if (pre_len[i] != -1 && pre_len_min[beg[i]] != -1 && pre_len[i] + pre_len_min[beg[i]] < min_len)
                min_len = pre_len[i] + pre_len_min[beg[i]];
        }
        return min_len == INT_MAX ? -1 : min_len;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{7, 3, 4, 7};
    int t = 7;
    Solution().minSumOfLengths(v, 7);
    return 0;
}
