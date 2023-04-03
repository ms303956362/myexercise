#include "usual.h"

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> cnt(value);
        for (const auto& num : nums) {
            int r = ((num % value) + value) % value;
            ++cnt[r];
        }
        int ans = 0, r = 0;
        while (cnt[r]) {
            --cnt[r];
            ++ans;
            r = (r + 1) % value;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
