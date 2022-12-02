#include "usual.h"

using ll = long long;

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        ll ans = 0, mod = 1e9 + 7;
        vector<ll> lpre(n + 1), lprepre(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            lpre[i] = (lpre[i + 1] + strength[i]) % mod;
        }
        for (int i = n - 1; i >= 0; --i) {
            lprepre[i] = (lprepre[i + 1] + lpre[i]) % mod;
        }
        vector<ll> rpre(n + 1), rprepre(n + 1);
        for (int i = 1; i <= n; ++i) {
            rpre[i] = (rpre[i - 1] + strength[i - 1]) % mod;
        }
        for (int i = 1; i <= n; ++i) {
            rprepre[i] = (rprepre[i - 1] + rpre[i]) % mod;
        }
        vector<ll> r(n, n), l(n, -1);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && strength[s.top()] > strength[i]) {
                s.pop();
            }
            if (!s.empty()) {
                l[i] = s.top();
            }
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && strength[s.top()] >= strength[i]) {
                s.pop();
            }
            if (!s.empty()) {
                r[i] = s.top();
            }
            s.push(i);
        }
        for (int i = 0; i < n; ++i) {
            ll jl = l[i] + 1, jr = r[i] - 1;
            ll cntl = i - jl, cntr = jr - i;
            ll lsum = lprepre[jl] - lprepre[i] - cntl * lpre[i];
            ll rsum = rprepre[jr + 1] - rprepre[i + 1] - cntr * rpre[i + 1];
            if (lsum < 0) {
                lsum += (-lsum / mod + 1) * mod;
            }
            if (rsum < 0) {
                rsum += (-rsum / mod + 1) * mod;
            }
            ll ltotal = (cntr + 1) * lsum % mod;
            ll rtotal = (cntl + 1) * rsum % mod;
            ll self = ((cntl + 1) * (cntr + 1) % mod) * strength[i] % mod;
            ans = (ans + strength[i] * ((ltotal + rtotal + self) % mod)) % mod;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{1, 3, 1, 2};
    Solution().totalStrength(v);
    return 0;
}
