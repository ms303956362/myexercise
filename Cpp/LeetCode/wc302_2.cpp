#include "usual.h"

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, multiset<int>> m;
        for (const auto& num : nums) {
            int s = digitSum(num);
            m[s].insert(num);
        }
        int ans = -1;
        for (const auto& [sum, st] : m) {
            if (st.size() >= 2) {
                int num1 = *st.rbegin(), num2 = *next(st.rbegin());
                ans = max(ans, num1 + num2);
            }
        }
        return ans;
    }

    int digitSum(int num) {
        int s = 0;
        while (num > 0) {
            s += num % 10;
            num /= 10;
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
