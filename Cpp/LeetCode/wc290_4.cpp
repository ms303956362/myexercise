#include "usual.h"

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> diff;
        for (const auto& f : flowers) {
            ++diff[f[0]];
            --diff[f[1] + 1];
        }
        int m = persons.size();
        vector<pair<int, int>> pi;
        for (int i = 0; i < m; ++i) {
            pi.emplace_back(persons[i], i);
        }
        sort(pi.begin(), pi.end());
        vector<int> ans(m);
        int j = 0, last = 0, sum = 0;
        for (const auto& [t, c] : diff) {
            while (j < m && pi[j].first < t) {
                ans[pi[j].second] = sum;
                ++j;
            }
            sum += c;
        }
        while (j < m) {
            ans[pi[j].second] = sum;
            ++j;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> f{{1, 10}, {3, 3}};
    vector<int> p{3, 3, 2};
    Solution().fullBloomFlowers(f, p);
    return 0;
}
