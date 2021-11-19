#include "usual.h"

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = *min_element(quantities.begin(), quantities.end());
        while (l <= r) {
            int x = (l + r) / 2, cnt = 0;
            cout << l << " " << r << " " << x << endl;
            for (const auto& q : quantities) {
                cnt += (q + x - 1) / x;
            }
            if (cnt >= n)
                l = x + 1;
            else
                r = x - 1;
        }
        return l;
    }
};

int main(int argc, char const *argv[])
{
    int n = 6;
    vector<int> q{11, 6};
    Solution().minimizedMaximum(n, q);
    return 0;
}
