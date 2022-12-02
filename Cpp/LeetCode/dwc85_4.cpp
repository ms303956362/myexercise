#include "usual.h"

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& a, vector<int>& removeQueries) {
        vector<long long> nums(a.begin(), a.end());
        int n = nums.size();
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        function<int(int)> find = [&](int u) {
            return p[u] == u ? u : (p[u] = find(p[u]));
        };
        auto merge = [&](int u, int v) {
            int pu = find(u), pv = find(v);
            if (pu == pv) {
                return false;
            }
            p[pu] = pv;
            nums[pv] += nums[pu];
            return true;
        };
        reverse(removeQueries.begin(), removeQueries.end());
        vector<long long> ans{0};
        vector<bool> vst(n, false);
        for (const auto& r : removeQueries) {
            if (r + 1 < n && vst[r + 1]) {
                merge(r, r + 1);
            }
            if (r - 1 >= 0 && vst[r - 1]) {
                merge(r, r - 1);
            }
            ans.push_back(max(ans.back(), nums[find(r)]));
            vst[r] = true;
        }
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
