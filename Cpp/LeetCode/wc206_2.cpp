#include "usual.h"

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& p, vector<vector<int>>& pairs) {
        int ans = 0;
        vector<vector<int>> preferences(n, vector<int>(n, 0));
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != n - 1; ++j) {
                preferences[i][p[i][j]] = n - j;
            }
        }
        vector<bool> vst(n, false);
        for (int i = 0; i < n / 2 - 1; ++i)
        {
            int x = pairs[i][0], y = pairs[i][1];
            for (int j = i + 1; j < n / 2; ++j)
            {
                int u = pairs[j][0], v = pairs[j][1];
                if (preferences[x][u] > preferences[x][y] && preferences[u][x] > preferences[u][v])
                {
                    if (!vst[x]) {
                        vst[x] = true;
                        ++ans;
                    }
                    if (!vst[u]) {
                        vst[u] = true;
                        ++ans;
                    }
                }
                if (preferences[x][v] > preferences[x][y] && preferences[v][x] > preferences[v][u])
                {
                    if (!vst[x]) {
                        vst[x] = true;
                        ++ans;
                    }
                    if (!vst[v]) {
                        vst[v] = true;
                        ++ans;
                    }
                }
                if (preferences[y][u] > preferences[y][x] && preferences[u][y] > preferences[u][v])
                {
                    if (!vst[y]) {
                        vst[y] = true;
                        ++ans;
                    }
                    if (!vst[u]) {
                        vst[u] = true;
                        ++ans;
                    }
                }
                if (preferences[y][v] > preferences[y][x] && preferences[v][y] > preferences[v][u])
                {
                    if (!vst[y]) {
                        vst[y] = true;
                        ++ans;
                    }
                    if (!vst[v]) {
                        vst[v] = true;
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> p{{ 1, 3, 2 }, { 2, 3, 0 }, { 1, 3, 0 }, { 0, 2, 1 }}, pairs{{ 1, 3 }, { 0, 2 }};
    int n = 4;
    cout << Solution().unhappyFriends(n, p, pairs) << endl;
    return 0;
}
