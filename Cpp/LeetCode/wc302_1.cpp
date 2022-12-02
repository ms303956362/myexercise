#include "usual.h"

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int, int> cnt;
        for (const auto& num : nums) {
            ++cnt[num];
        }
        vector<int> ans(2);
        for (const auto& [num, c] : cnt) {
            ans[0] += c / 2;
            ans[1] += c % 2;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
