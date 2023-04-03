#include "usual.h"

using ll = long long;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<tuple<ll, ll, ll>> v;
        set<pair<ll, ll>> s1, s2;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums1[i];
            s1.emplace(nums1[i], i);
            v.emplace_back(nums2[i], nums1[i], i);
        }
        while (s1.size() > k - 1) {
            auto p = s1.begin();
            sum -= p->first;
            s2.insert(*p);
            s1.erase(p);
        }
        sort(v.begin(), v.end());
        ll ans = 0;
        for (int i = 0; i <= n - k; ++i) {
            auto [v2, v1, j] = v[i];
            if (s1.count(make_pair(v1, j))) {
                s1.erase(make_pair(v1, j));
                sum -= v1;
                auto p = prev(s2.end());
                sum += p->first;
                s1.insert(*p);
                s2.erase(p);
            } else {
                s2.erase(make_pair(v1, j));
            }
            ans = max(ans, v2 * (sum + v1));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
