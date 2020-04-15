#include "usual.h"

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        vector<vector<bool>> vst(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                if (a[i][j] == 0) {
                    q.push({i, j});
                    vst[i][j] = true;
                }
            }
        }
        while (!q.empty()) {
            auto [k, l] = q.front();
            q.pop();
            int level = v[k][l] + 1;
            if (k > 0 && !vst[k - 1][l]) {
                v[k - 1][l] = level;
                vst[k - 1][l] = true;
                q.push({k - 1, l});
            }
            if (k < n - 1 && !vst[k + 1][l]) {
                v[k + 1][l] = level;
                vst[k + 1][l] = true;
                q.push({k + 1, l});
            }
            if (l > 0 && !vst[k][l - 1]) {
                v[k][l - 1] = level;
                vst[k][l - 1] = true;
                q.push({k, l - 1});
            }
            if (l < m - 1 && !vst[k][l + 1]) {
                v[k][l + 1] = level;
                vst[k][l + 1] = true;
                q.push({k, l + 1});
            }
        }
        return v;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v{{0, 1, 0}, {0, 1, 0}, {0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    Solution().updateMatrix(v);

    return 0;
}
