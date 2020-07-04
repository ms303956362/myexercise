#include "usual.h"

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int min_i = INT_MAX, max_i = INT_MIN;
        for (auto i : arr) {
            min_i = min(min_i, i);
            max_i = max(max_i, i);
        }
        int l = min_i, r = max_i;
        while (l < r) {
            int m = (l + r) >> 1;
            int sum = 0;
            for (int i : arr) {
                sum += min(m, i);
            }
            if (sum < target)
                l = m;
            else
                r = m;
        }
        return l;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{4, 9, 3};
    int t = 10;
    Solution().findBestValue(v, t);
    return 0;
}
