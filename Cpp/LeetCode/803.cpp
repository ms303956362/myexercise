#include "usual.h"

class DSU {
    int n;
    vector<int> p;
    vector<int> sz;

public:
    DSU(int _n) : n(_n), p(_n), sz(_n, 1) {
        for (int i = 0; i != _n; ++i) 
            p[i] = i;
    }

    int find(int x) {
        return x == p[x] ? x : (p[x] = find(p[x]));
    }

    int size(int x) {
        return sz[find(x)];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py)
            return false;
        p[px] = py;
        sz[py] += sz[px];
        cout << sz[py] << endl;
        return true;
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> status(grid);
        for (const auto& hit : hits) {
            status[hit[0]][hit[1]] = 0;
        }
        DSU s(n * m + 1);
        // cout << "ok" << endl;
        for (int j = 0; j != m; ++j) {
            if (status[0][j] == 1)
                s.unite(j, n * m);
        }
        // cout << "ok" << endl;
        vector<pair<int, int>> dxdy{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 1; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                if (status[i][j] == 0)
                    continue;
                for (const auto& [dx, dy] : dxdy) {
                    int x = i + dx, y = j + dy;
                    if (0 <= x && x < n && 0 <= y && y < m && status[x][y]) {
                        // cout << i << " " << j << " " << x << " " << y << endl;
                        s.unite(m * i + j, m * x + y);
                    }
                }
            }
        }
        // cout << endl;
        vector<int> ans(hits.size(), 0);
        int prev = s.size(n * m), now = 0;
        for (int k = hits.size() - 1; k >= 0; --k) {
            int i = hits[k][0], j = hits[k][1];
            if (grid[i][j] == 0)
                continue;
            status[i][j] = 1;
            if (i == 0)
                s.unite(j, n * m);
            for (const auto& [dx, dy] : dxdy) {
                int x = i + dx, y = j + dy;
                if (0 <= x && x < n && 0 <= y && y < m && status[x][y]) {
                    cout << "(i,j)=(" << i << "," << j << ") (x,y)=(" << x << "," << y <<")" << endl;
                    s.unite(m * i + j, m * x + y);
                }
            }
            now = s.size(n * m);
            ans[k] = max(0, now - prev - 1);
            prev = now;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grids{{1,0,1},{1,1,1}}, hits{{0,0},{0,2},{1,1}};
    Solution().hitBricks(grids, hits);
    return 0;
}
