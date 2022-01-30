#include "usual.h"

class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size(), cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (corridor[i] == 'S')
                ++cnt;
        }
        if (cnt == 0 || cnt % 2 != 0)
            return 0;
        vector<long long> nums;
        int last = -1;
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (corridor[i] == 'S') {
                if (cnt == 0) {
                    if (last != -1) {
                        nums.push_back(i - last);
                    }
                    ++cnt;
                } else {
                    last = i;
                    cnt = 0;
                }
            }
        }
        long long ans = 1, mod = 1e9 + 7;
        for (const auto& num : nums) {
            ans = (ans * num) % mod;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
