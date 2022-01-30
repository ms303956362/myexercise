#include "usual.h"

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> g(n);
        vector<bool> vst(n, false);
        for (const auto& m : meetings) {
            g[m[0]].emplace_back(m[1], m[2]);
            g[m[1]].emplace_back(m[0], m[2]);
        }
        g[0].emplace_back(firstPerson, 0);
        g[firstPerson].emplace_back(0, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.emplace(-1, 0);
        while (!q.empty()) {
            auto [time, u] = q.top();
            q.pop();
            if (vst[u])
                continue;
            vst[u] = true;
            for (const auto& [v, t] : g[u]) {
                if (!vst[v] && t >= time)
                    q.emplace(t, v);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (vst[i])
                ans.push_back(i);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
