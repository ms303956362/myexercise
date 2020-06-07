#include "usual.h"

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int lj, hj;
        int INF = 1e9;
        vector<vector<vector<int>>> f(105, vector<vector<int>>(25, vector<int>(105, INF)));
        for (int j = 0; j != n; ++j) {
            f[m][j][0] = 0;
        }
        for (int i = m - 1; i >= 0; --i)
        {
            if (houses[i] == 0)
            { // not colored
                lj = 0;
                hj = n;
            }
            else
            { // colored
                lj = houses[i] - 1;
                hj = houses[i];
            }
            for (int j = lj; j != hj; ++j)
            {
                for (int k = 1; k <= target; ++k)
                {
                    int c = INF;
                    for (int p = 0; p != n; ++p)
                    {
                        if (p == j)
                            c = min(c, f[i + 1][p][k]);
                        else
                            c = min(c, f[i + 1][p][k - 1]);
                    }
                    if (lj == houses[i] - 1 && hj == houses[i]) {
                        f[i][j][k] = c;
                    } else {
                        f[i][j][k] = c + cost[i][j];
                    }
                }
            }
        }
        int min_c = INF;
        for (int j = 0; j != n; ++j) {
            min_c = min(min_c, f[0][j][target]);
        }
        return min_c < INF ? min_c : -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> h{0, 2, 1, 2, 0};
    vector<vector<int>> c{{1, 10}, { 10, 1 }, { 10, 1 }, { 1, 10 }, { 5, 1 }};
    int m = 5, n = 2, t = 3;
    cout << Solution().minCost(h, c, m, n, t) << endl;
    return 0;
}
