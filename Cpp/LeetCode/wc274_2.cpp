#include "usual.h"

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(), n = bank[0].size();
        vector<int> nums;
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (bank[i][j] == '1')
                    ++cnt;
            }
            if (cnt > 0)
                nums.push_back(cnt);
        }
        if (nums.size() <= 1)
            return 0;
        int l = nums.size(), ans = 0;
        for (int i = 0; i < l - 1; ++i) {
            ans += nums[i] * nums[i + 1];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
