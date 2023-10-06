#include "usual.h"

class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> ans(n, -1);
        vector<int> path, idx(n, -1);
        auto find_cycle = [&](int u) {
            while (idx[u] == -1 && ans[u] == -1) {
                idx[u] = path.size();
                path.push_back(u);
                u = edges[u];
            }
            int sz = ans[u];
            if (ans[u] == -1) {
                sz = path.size() - idx[u];
                int i = idx[u];
                while (path.size() > i) {
                    ans[path.back()] = sz;
                    idx[path.back()] = -1;
                    path.pop_back();
                }
            }
            int cnt = 0;
            while (path.size() > 0) {
                ++cnt;
                ans[path.back()] = cnt + sz;
                idx[path.back()] = -1;
                path.pop_back();
            }
        };
        for (int i = 0; i < n; ++i) {
            if (ans[i] > 0) {
                continue;
            }
            find_cycle(i);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
