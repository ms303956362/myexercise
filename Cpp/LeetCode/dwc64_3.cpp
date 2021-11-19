#include "usual.h"

// class Solution {
// public:
//     vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
//         int n = s.size();
//         vector<int> lc(n), rc(n), pre(n + 1);
//         int c = -1;
//         pre[0] = 0;
//         for (int i = 0; i < n; ++i) {
//             pre[i + 1] = pre[i] + (s[i] == '*');
//             if (s[i] == '|')
//                 c = i;
//             lc[i] = c;
//         }
//         c = -1;
//         for (int i = n - 1; i >= 0; --i) {
//             if (s[i] == '|')
//                 c = i;
//             rc[i] = c;
//         }
//         vector<int> ans;
//         for (const auto& q : queries) {
//             if (rc[q[0]] == -1 || lc[q[1]] == -1 || rc[q[0]] > lc[q[1]]) {
//                 ans.push_back(0);
//             } else {
//                 ans.push_back(pre[lc[q[1]] + 1] - pre[rc[q[0]] + 1]);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
    int ans;
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        int n = pieces.size();
        vector<pair<int, int>> dirs{{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        vector<pair<int, int>> d;
        vector<vector<int>> feasible;
        for (const auto& s : pieces) {
            if (s == "rook")
                feasible.push_back({1, 2, 3, 4});
            else if (s == "queen")
                feasible.push_back({1, 2, 3, 4, 5, 6, 7, 8});
            else
                feasible.push_back({5, 6, 7, 8});
        }
        ans = 0;
        for (auto& p : positions) {
            --p[0];
            --p[1];
        }
        dfs(0, n, d, positions, dirs, feasible);
        return ans;
    }

    void dfs(int i, int n, vector<pair<int, int>>& d, vector<vector<int>>& p, vector<pair<int, int>>& dirs, vector<vector<int>>& feasible) {
        if (i == n) {
            if (go(d, p, dirs))
                ++ans;
            return;
        }
        d.emplace_back(0, 0);
        dfs(i + 1, n, d, p, dirs, feasible);
        d.pop_back();
        for (int j = 0; j < feasible[i].size(); ++j) {
            int t = 1, x = p[i][0] + dirs[feasible[i][j]].first, y = p[i][1] + dirs[feasible[i][j]].second;
            while (0 <= x && x < 8 && 0 <= y && y < 8) {
                d.emplace_back(feasible[i][j], t);
                dfs(i + 1, n, d, p, dirs, feasible);
                d.pop_back();
                x += dirs[feasible[i][j]].first;
                y += dirs[feasible[i][j]].second;
                ++t;
            }
        }
    }

    bool go(vector<pair<int, int>>& d, vector<vector<int>>& p, vector<pair<int, int>>& dirs) {
        vector<vector<int>> board(8, vector<int>(8, -1));
        int n = p.size();
        for (int i = 0; i < n; ++i) {
            if (d[i].second != 0) {
                board[p[i][0]][p[i][1]] = i;
            } else {
                board[p[i][0]][p[i][1]] = -2;
            }
        }
        bool ok = true;
        int t = 0;
        while (ok) {
            ok = false;
            for (int i = 0; i < n; ++i) {
                if (t < d[i].second) {
                    int x = p[i][0] + t * dirs[d[i].first].first, y = p[i][1] + t * dirs[d[i].first].second;
                    if (board[x][y] == i)
                        board[x][y] = -1;
                    x += dirs[i].first;
                    y += dirs[i].second;
                    if (board[x][y] == -2 || (board[x][y] >= 0 && board[x][y] < i))
                        return false;
                    board[x][y] = i;
                    ok = true;
                } else {
                    int x = p[i][0] + t * dirs[i].first, y = p[i][1] + t * dirs[i].second;
                    board[x][y] = -2;
                }
            }
            ++t;
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    vector<string> s{"rook", "rook"};
    vector<vector<int>> v{{1, 1}, {8, 8}};
    Solution().countCombinations(s, v);
    return 0;
}
