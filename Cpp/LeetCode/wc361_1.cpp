#include "usual.h"

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        auto check = [](int num) {
            string s = to_string(num);
            if (s.size() % 2 != 0) {
                return false;
            }
            int n = s.size();
            int s1 = 0, s2 = 0;
            for (int i = 0; i < n / 2; ++i) {
                s1 += s[i] - '0';
            }
            for (int i = n / 2; i < n; ++i) {
                s2 += s[i] - '0';
            }
            return s1 == s2;
        };
        int ans = 0;
        for (int i = low; i <= high; ++i) {
            if (check(i)) {
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
