#include "usual.h"

class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        int n = s.size(), ans = INT_MAX;
        for (int t = 0; t < (1 << n); ++t) {
            vector<int> d1, d2;
            for (int i = 0; i < n; ++i) {
                if (t & (1 << i)) {
                    d1.push_back(s[i] - '0');
                } else {
                    d2.push_back(s[i] - '0');
                }
            }
            sort(d1.begin(), d1.end());
            sort(d2.begin(), d2.end());
            int num1 = 0, num2 = 0;
            for (const auto& d : d1) {
                num1 = num1 * 10 + d;
            }
            for (const auto& d : d2) {
                num2 = num2 * 10 + d;
            }
            ans = min(ans, num1 + num2);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
