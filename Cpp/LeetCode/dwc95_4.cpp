#include "usual.h"

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        long long ans = 0, l = 0, h = 1e11;
        vector<long long> pre(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            pre[i] = pre[i + 1] + stations[i];
        }
        auto check = [&](long long m) {
            long long cnt = 0;
            vector<long long> diff(n + 1);
            long long extra = 0;
            for (int i = 0; i < n; ++i) {
                int L = max(i - r, 0), R = min(i + r + 1, n);
                extra += diff[i];
                long long sum = pre[L] - pre[R] + extra;
                if (sum < m) {
                    cnt += m - sum;
                    extra += m - sum;
                    diff[min(i + 2 * r + 1, n)] += sum - m;
                }
            }
            return cnt <= k;
        };
        while (l <= h) {
            long long m = (l + h) / 2;
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
