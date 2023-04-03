#include "usual.h"

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            long long num1 = nums[i], num2 = nums[j];
            string s1 = to_string(num1), s2 = to_string(num2);
            long long num = stoll(s1 + s2);
            ans += num;
            ++i;
            --j;
        }
        if (i == j) {
            ans += nums[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
