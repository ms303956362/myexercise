#include "usual.h"

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int> ps;
        auto is_prime = [](int i) {
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 2; i <= 1000; ++i) {
            if (is_prime(i)) {
                ps.push_back(i);
            }
        }
        unordered_set<int> ans;
        for (const auto& num : nums) {
            for (const auto& p : ps) {
                if (num % p == 0) {
                    ans.insert(p);
                }
            }
        }
        return ans.size();
    }
};