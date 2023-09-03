#include "usual.h"

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> diff(n + 1);
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += diff[i];
            if (nums[i] + sum > 0) {
                if (i <= n - k) {
                    long long d = nums[i] + sum;
                    diff[i + k] += d;
                    sum -= d;
                } else {
                    return false;
                }
            }
            if (nums[i] + sum < 0) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
