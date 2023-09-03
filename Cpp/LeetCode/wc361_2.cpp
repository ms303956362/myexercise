#include "usual.h"

class Solution {
public:
    int minimumOperations(string num) {
        unordered_set<char> st(num.begin(), num.end());
        int n = num.size(), ans = st.count('0') ? (n - 1) : n;
        reverse(num.begin(), num.end());
        auto check = [&](int d2, int d1) {
            int cnt = 0, i = 0;
            while (i < n && num[i] != d1 + '0') {
                ++cnt;
                ++i;
            }
            if (i == n) {
                return n;
            }
            ++i;
            while (i < n && num[i] != d2 + '0') {
                ++cnt;
                ++i;
            }
            if (i == n) {
                return n;
            }
            return cnt;
        };
        ans = min({ans, check(0, 0), check(2, 5), check(5, 0), check(7, 5)});
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
