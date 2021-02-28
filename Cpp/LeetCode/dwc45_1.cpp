#include "usual.h"

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> cnt(105, 0);
        for (const auto& n : nums) {
            ++cnt[n];
        }
        int ans = 0;
        for (int i = 0; i != 105; ++i) {
            if (cnt[i] == 1)
                ans += i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
