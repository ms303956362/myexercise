#include "usual.h"

class Solution {
public:
    bool isCompliance(vector<vector<int>>& distance, int n) {
        int m = distance.size(), sz = m;
        vector<int> p(m);
        for (int i = 0; i < m; ++i) {
            p[i] = i;
        }
        function<int(int)> find = [&](int u)
        {
            return p[u] == u ? u : (p[u] = find(p[u]));
        };
        auto merge = [&](int u, int v)
        {
            int pu = find(u), pv = find(v);
            if (pu == pv) {
                return false;
            }
            p[pu] = pv;
            --sz;
            return true;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                if (distance[i][j] <= 2) {
                    merge(i, j);
                }
            }
        }
        return sz <= n;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
