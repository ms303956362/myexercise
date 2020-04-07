#include "usual.h"

class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> cnt(26, 0);
        for (auto& c : s) {
            ++cnt[c - 'a'];
        }
        int sum = 0, sum_odd = 0;
        for (auto& num : cnt) {
            if (num % 2 == 1) {
                ++sum_odd;
            }
            sum += num;
        }
        return sum >= k && sum_odd <= k;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().canConstruct("putmeinatrouble", 16) << endl;
    return 0;
}
