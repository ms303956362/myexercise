#include "usual.h"

class Solution {
public:
    int coopDevelop(vector<vector<int>>& skills) {
        long long ans = 0, mod = 1e9 + 7, n = skills.size();
        sort(skills.begin(), skills.end(), [](const vector<int> &l, const vector<int> &r) {
            return l.size() > r.size();
        });
        unordered_map<long long, int> cnt;
        for (const auto& sk : skills) {
            int m = sk.size();
            long long state = 0;
            for (int i = 0; i < m; ++i) {
                state = (state << 10) + sk[i];
            }
            ans += cnt[state];
            for (int s = 1; s < (1 << m); ++s) {
                state = 0;
                for (int i = 0; i < m; ++i) {
                    if ((s & (1 << i)) > 0)
                        continue;
                    state = (state << 10) + sk[i];
                }
                ++cnt[state];
            }
        }
        return (n * (n - 1) / 2 - ans) % mod;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v{{1, 2, 3}, {3}, {2, 4}};
    Solution().coopDevelop(v);
    return 0;
}
