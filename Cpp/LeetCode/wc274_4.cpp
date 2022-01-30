#include "usual.h"

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> vst(n, -1);    
        int step = 0, max_cycle = 0;
        function<void(int)> dfs = [&](int u)
        {
            int v = favorite[u];
            if (vst[v] == -1) {
                ++step;
                vst[v] = step;
                dfs(v);
            } else {
                max_cycle = max(max_cycle, step - vst[v] + 1);
            }
            vst[u] = 0x3f3f3f3f;
        };
        for (int i = 0; i < n; ++i) {
            if (vst[i] == -1) {
                step = 0;
                vst[i] = 0;
                dfs(i);
            }
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            g[favorite[i]].push_back(i);
        }
        int max_pairs = 0;
        function<int(int)> dfs2 = [&](int u)
        {
            int ret = 0;
            for (const auto& v : g[u])
            {
                if (v != favorite[u])
                    ret = max(ret, dfs2(v));
            }
            return ret + 1;
        };
        for (int i = 0; i < n; ++i) {
            if (i < favorite[i] && i == favorite[favorite[i]]) {
                max_pairs += dfs2(i) + dfs2(favorite[i]);
            }
        }
        return max(max_cycle, max_pairs);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{23,14,17,5,19,2,0,18,15,12,2,8,21,3,3,1,6,5,11,17,3,7,14,13};
    Solution().maximumInvitations(v);
    return 0;
}
