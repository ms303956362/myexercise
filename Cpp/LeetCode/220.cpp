#include "usual.h"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (n <= 1 || k == 0)
            return false;
        if (k >= n)
            k = n - 1;
        multiset<int> s;
        for (int i = 0; i != k + 1; ++i) {
            s.insert(nums[i]);
        }
        for(auto p = s.begin(), q = ++s.begin(); q != s.end(); ++p, ++q) {
            if (*q - *p <= t)
                return true;
        }
        for (int i = 1; i != n - k; ++i) {
            s.erase(nums[i - 1]);
            auto p = s.insert(nums[i + k]);
            auto q = p, m = p;
            if (m != s.begin() && *p - *(--m) <= t || ++q != s.end() && *q - *p <= t)
                return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{1,5,9,1,5,9};
    int k = 2, t = 3;
    cout << Solution().containsNearbyAlmostDuplicate(v, k, t) << endl;
    return 0;
}
