#include "usual.h"

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> cnt;
        for (const auto& num : nums) {
            ++cnt[num];
        }
        int ans = -1, max_c = 0;
        for (const auto& [num, c] : cnt) {
            if (num % 2 == 0 && c > max_c) {
                max_c = c;
                ans = num;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
