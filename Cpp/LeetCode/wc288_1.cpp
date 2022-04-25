#include "usual.h"

class Solution {
public:
    int largestInteger(int num) {
        vector<int> odds, evens, flags, digits;
        while (num > 0) {
            int d = num % 10;
            if (d % 2 == 0) {
                evens.push_back(d);
                flags.push_back(0);
            } else {
                odds.push_back(d);
                flags.push_back(1);
            }
            num /= 10;
        }
        sort(odds.begin(), odds.end());
        sort(evens.begin(), evens.end());
        int m = flags.size();
        for (int i = m - 1; i >= 0; --i) {
            if (flags[i]) {
                digits.push_back(odds.back());
                odds.pop_back();
            } else {
                digits.push_back(evens.back());
                evens.pop_back();
            }
        }
        reverse(digits.begin(), digits.end());
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            ans = ans * 10 + digits[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
