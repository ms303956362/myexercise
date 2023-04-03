#include "usual.h"

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n);
        vector<int> d(n);
        for (const auto& e : edges) {
            ++d[e[0] - 1];
            ++d[e[1] - 1];
            g[e[0] - 1].insert(e[1] - 1);
            g[e[1] - 1].insert(e[0] - 1);
        }
        vector<int> odds;
        for (int i = 0; i < n; ++i) {
            if (d[i] % 2 == 1) {
                odds.push_back(i);
            }
        }
        if (odds.size() == 0) {
            return true;
        }
        if (odds.size() == 2) {
            if (!g[odds[0]].count(odds[1])) {
                return true;
            }
            for (int i = 0; i < n; ++i) {
                if (!g[i].count(odds[0]) && !g[i].count(odds[1])) {
                    return true;
                }
            }
        }
        if (odds.size() == 4) {
            int x0 = odds[0], x1 = odds[1], x2 = odds[2], x3 = odds[3];
            if (!g[x0].count(x1) && !g[x2].count(x3) || 
            !g[x0].count(x2) && !g[x1].count(x3) || 
            !g[x0].count(x3) && !g[x1].count(x2)) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
