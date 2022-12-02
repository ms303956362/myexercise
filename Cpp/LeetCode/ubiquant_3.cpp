#include "usual.h"

class Solution {
public:
    int minOperations(vector<int>& numbers) {
        int max_2 = 0, max_3 = 0;
        int gcd = numbers[0];
        for (const auto& num : numbers) {
            gcd = __gcd(gcd, num);
        }
        vector<pair<int, int>> cnts;
        for (auto& num : numbers) {
            int cnt2 = 0, cnt3 = 0;
            num /= gcd;
            while (num % 2 == 0) {
                ++cnt2;
                num /= 2;
            }
            while (num % 3 == 0) {
                ++cnt3;
                num /= 3;
            }
            if (num != 1) {
                return -1;
            }
            cnts.emplace_back(cnt2, cnt3);
            max_2 = max(max_2, cnt2);
            max_3 = max(max_3, cnt3);
        }
        int ans = 0;
        for (const auto& [cnt2, cnt3] : cnts) {
            ans += max_2 - cnt2 + max_3 - cnt3;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
