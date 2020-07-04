#include "usual.h"

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> cnt(k, 0);
        for (auto i : arr) {
            if (i < 0)
                i = i % k + k;
            ++cnt[i % k];
        }
        if (k % 2 == 0 && cnt[k / 2] % 2 != 0)
            return false;
        for (int i = 1; i < k; ++i) {
            if (cnt[i] != cnt[k - i])
                return false;
        }
        return true;
    }
};