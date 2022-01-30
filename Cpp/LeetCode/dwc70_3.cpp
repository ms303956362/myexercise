#include "usual.h"

struct Node
{
    int dis;
    int price;
    int row;
    int col;
    Node(int d, int p, int r, int c): dis(d), price(p), row(r), col(c) {}
};

bool operator<(const Node& ln, const Node& rn) {
    return ln.dis < rn.dis || (ln.dis == rn.dis && ln.price < rn.price) || (ln.dis == rn.dis && ln.price == rn.price && ln.row < rn.row) || (ln.dis == rn.dis && ln.price == rn.price && ln.row == rn.row && ln.col < rn.col);
}

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vst(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<Node> pq;
        vst[start[0]][start[1]] = true;
        q.emplace(start[0], start[1]);
        int step = 0;
        while (!q.empty()) {
            int l = q.size();
            ++step;
            for (int i = 0; i < l; ++i) {
                auto [x, y] = q.front();
                q.pop();
                if (grid[x][y] > 1 && pricing[0] <= grid[x][y] && grid[x][y] <= pricing[1]) {
                    // compare
                    Node tmp(step, grid[x][y], x, y);
                    if (pq.size() >= k) {
                        if (tmp < pq.top()) {
                            pq.pop();
                            pq.push(tmp);
                        }
                    } else {
                        pq.push(tmp);
                    }
                }
                for (const auto& [dx, dy] : dirs) {
                    int u = x + dx, v = y + dy;
                    if (0 <= u && u < m && 0 <= v && v < n && grid[u][v] != 0 && !vst[u][v]) {
                        vst[u][v] = true;
                        q.emplace(u, v);
                    }
                }
            }
            if (pq.size() == k)
                break;
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back({pq.top().row, pq.top().col});
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> a{{2, 0, 2}, {4, 5, 3}, {2, 0, 2}};
    vector<int> p{2, 5}, s{1, 1};
    int k = 9;
    Solution().highestRankedKItems(a, p, s, k);
    return 0;
}
