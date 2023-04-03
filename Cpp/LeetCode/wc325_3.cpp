#include "usual.h"

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int l = 1, h = 1e9 + 7, ans = 0;
        auto check = [&](int m) {
            int i = 1;
            vector<int> a;
            a.push_back(price[0]);
            while (i < n) {
                while (i < n && price[i] - a.back() < m) {
                    ++i;
                }
                if (i < n) {
                    a.push_back(price[i]);
                }
                ++i;
            }
            return a.size() >= k;
        };
        while (l <= h) {
            int m = (l + h) / 2;
            if (check(m)) {
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
