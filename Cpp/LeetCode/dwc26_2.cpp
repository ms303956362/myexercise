#include "usual.h"

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (__gcd(i, j) == 1) {
                    string s = to_string(j) + "/" + to_string(i);
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution().simplifiedFractions(4);
    return 0;
}
