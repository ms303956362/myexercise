#include "usual.h"

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row_mx(m), col_mx(n);
        priority_queue<tuple<int, int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                q.emplace(mat[i][j], i, j);
            }
        }
        int ans = 0;
        while (!q.empty()) {
            int val = get<0>(q.top());
            vector<tuple<int, int, int>> v;
            while (!q.empty() && get<0>(q.top()) == val) {
                auto [_, i, j] = q.top();
                q.pop();
                int cnt = max(row_mx[i], col_mx[j]) + 1;
                ans = max(ans, cnt);
                v.emplace_back(cnt, i, j);
            }
            for (const auto& [cnt, i, j] : v) {
                row_mx[i] = max(row_mx[i], cnt);
                col_mx[j] = max(col_mx[j], cnt);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
