#include "usual.h"

using ll = long long;

class BIT {
    ll n;
    vector<ll> tree;
public:
    BIT(ll _n) : n(_n + 1), tree(_n + 1, 0) {}
    BIT(const vector<ll>& a) : n(a.size() + 1), tree(a.size() + 1, 0) {
        for (ll i = 1; i < n; ++i) {
            update(i - 1, a[i - 1]);
        }
    }

    inline ll lowBit(ll i) { return i & (-i); }

    void update(ll i, ll delta) {
        ++i;
        while (i < n) {
            tree[i] += delta;
            i += lowBit(i);
        }
    }

    ll query(ll i) {
        ++i;
        ll sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= lowBit(i);
        }
        return sum;
    }

};

const int maxn = 1e5;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = nums1[i] - nums2[i];
        }
        BIT t(2 * maxn);
        t.update(a[0] - diff + maxn, 1);
        ll ans = 0;
        for (int i = 1; i < n; ++i) {
            ans += t.query(a[i] + maxn);
            t.update(a[i] - diff + maxn, 1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
