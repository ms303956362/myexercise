#include "usual.h"

class Solution {
    using ll = long long;

public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        ll full_now = 0;
        vector<ll> notfulls;
        for (const auto& f : flowers) {
            if (f < target) {
                notfulls.push_back(f);
            } else {
                ++full_now;
            }
        }
        ll n = notfulls.size();
        sort(notfulls.rbegin(), notfulls.rend());
        auto max_partial = [&](int c, ll limit, ll lb) {
            if (c == n) {
                return (ll)0;
            }
            ll l = lb, h = target - 1;
            while (l <= h) {
                ll m = (l + h) / 2, sum = 0;
                for (int i = c; i < n; ++i) {
                    if (m > notfulls[i]) {
                        sum += m - notfulls[i];
                    }
                }
                if (sum <= limit) {
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }
            return h;
        };
        ll total_need = 0;
        for (int i = 0; i < n; ++i) {
            total_need += target - 1 - notfulls[i];
        }
        ll ans = 0, last_p = -1;
        ll limit = newFlowers;
        for (ll c = 0; c <= n; ++c) {
            ll cnt_full = full_now + c;
            if (c > 0) {
                limit -= target - notfulls[c - 1];
            }
            if (limit < 0) {
                break;
            }
            ll max_p = max_partial(c, limit, last_p == -1 ? 0 : last_p);
            last_p = max_p;
            if (max_p >= 0) {
                ans = max(ans, cnt_full * full + max_p * partial);
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> a{2,4,5,3};
    long long nf = 10;
    int t = 5, f = 2, p = 6;
    Solution().maximumBeauty(a, nf, t, f, p);
    return 0;
}
