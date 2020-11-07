#include "usual.h"
// struct Node {
//     int first;
//     int second;
//     Node(int f, int s) : first(f), second(s) {}
    
// };

// bool operator<(const Node &n1, const Node &n2) { return n1.first < n2.first; }

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m, 0)), ans1(n, vector<int>(m, 0)), ans2(n, vector<int>(m, 0));
        vector<pair<int, int>> rp, cp;
        for (int i = 0; i != n; ++i) {
            rp.push_back({rowSum[i], i});
        }
        for (int i = 0; i != m; ++i) {
            cp.push_back({colSum[i], i});
        }
        sort(rp.begin(), rp.end());
        sort(cp.begin(), cp.end());
        sort(rowSum.begin(), rowSum.end());
        sort(colSum.begin(), colSum.end());
        for (int i = 0; i != min(n, m); ++i) {
            ans[i][i] = min(rowSum[i], colSum[i]);
            if (i < min(n, m) - 1) {
                if (rowSum[i] < colSum[i]) {
                    ans[i + 1][i] = colSum[i] - rowSum[i];
                    rowSum[i + 1] -= ans[i + 1][i];
                } else {
                    ans[i][i + 1] = rowSum[i] - colSum[i];
                    colSum[i + 1] -= ans[i][i + 1];
                }
            }
        }
        if (m < n) {
            for (int i = m; i < n; ++i) {
                ans[i][m - 1] = rowSum[i];
            }
        } else if (n < m) {
            for (int i = n; i < m; ++i) {
                ans[n - 1][i] = colSum[i];
            }
        }
        for (int i = 0; i != n; ++i) {
            ans1[rp[i].second] = ans[i];
        }
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j)
                ans2[j][cp[i].second] = ans1[j][i];
        }
        return ans2;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> rs{14, 9}, cs{6, 9, 8};
    Solution().restoreMatrix(rs, cs);
    return 0;
}
