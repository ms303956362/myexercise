#include "usual.h"

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> cnt, cnt1, cnt2;
        for (const auto& c : basket1) {
            ++cnt[c];
            ++cnt1[c];
        }
        for (const auto& c : basket2) {
            ++cnt[c];
            ++cnt2[c];
        }
        vector<long long> v;
        for (const auto& [x, _] : cnt1) {
            if (cnt[x] % 2 == 1) {
                return -1;
            }
            int l = cnt1[x] - (cnt[x] / 2);
            for (int i = 0; i < l; ++i) {
                v.push_back(x);
            }
        }
        for (const auto& [x, _] : cnt2) {
            if (cnt[x] % 2 == 1) {
                return -1;
            }
            int l = cnt2[x] - (cnt[x] / 2);
            for (int i = 0; i < l; ++i) {
                v.push_back(x);
            }
        }
        sort(v.begin(), v.end());
        int m = v.size();
        long long mn = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end())), ans = 0;
        for (int i = 0; i < m / 2; ++i) {
            ans += min(v[i], 2 * mn);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
