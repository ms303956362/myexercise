#include "usual.h"

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n = items.size();
        vector<pair<long long, int>> v;
        for (const auto& it : items) {
            v.emplace_back(it[0], it[1]);
        }
        sort(v.rbegin(), v.rend());
        long long total = 0;
        unordered_map<int, unordered_multiset<long long>> mp;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q2;
        for (int i = 0; i < k; ++i) {
            auto [val, c] = v[i];
            total += val;
            mp[c].insert(val);
            q2.emplace(val, c);
        }
        long long sz = mp.size(), ans = total + sz * sz;
        unordered_map<int, long long> mxmp;
        for (int i = k; i < n; ++i) {
            auto [val, c] = v[i];
            if (mp.count(c)) {
                continue;
            }
            if (val > mxmp[c]) {
                mxmp[c] = val;
            }
        }
        priority_queue<long long> q;
        for (const auto& [_, val] : mxmp) {
            q.push(val);
        }
        while (!q.empty() && !q2.empty()) {
            while (!q2.empty() && mp[q2.top().second].size() <= 1) {
                q2.pop();
            }
            if (q2.empty()) {
                break;
            }
            auto val = q.top();
            q.pop();
            auto [val2, c2] = q2.top();
            q2.pop();
            mp[c2].extract(val2);
            total += val - val2;
            ++sz;
            ans = max(ans, total + sz * sz);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v{{3,2},{5,1},{10,1}};
    int k = 2;
    Solution().findMaximumElegance(v, k);
    return 0;
}
