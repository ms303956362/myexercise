#include "usual.h"

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> in(n);
        vector<vector<bool>> g(n, vector<bool>(n, false));
        for (const auto& e : edges) {
            g[e[0] - 1][e[1] - 1] = true;
            g[e[1] - 1][e[0] - 1] = true;
            ++in[e[0] - 1];
            ++in[e[1] - 1];
        }
        int ans = INT_MAX;
        for (int i = 0; i != n - 2; ++i) {
            for (int j = i + 1; j != n - 1; ++j) {
                for (int k = j + 1; k != n; ++k) {
                    if (g[i][j] && g[j][k] && g[k][i])
                        ans = min(ans, in[i] + in[j] + in[k] - 6);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
