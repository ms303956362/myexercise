#include "usual.h"

class Solution {
public:
    int minimumSum(int num) {
        vector<int> digits(4);
        for (int i = 0; i < 4; ++i) {
            digits[i] = num % 10;
            num /= 10;
        }
        int ans = INT_MAX;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (j == i)
                    continue;
                for (int p = 0; p < 4; ++p) {
                    if (p == i || p == j) {
                        continue;
                    }
                    for (int q = 0; q < 4; ++ q) {
                        if (q == i || q == j || q == p) {
                            continue;
                        }
                        ans = min({ans, digits[i] + 100 * digits[j] + 10 * digits[p] + digits[q], 10 * digits[i] + digits[j] + 10 * digits[p] + digits[q], 100 * digits[i] + 10 * digits[j] + digits[p] + digits[q]});
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
