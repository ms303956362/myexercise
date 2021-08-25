#include "usual.h"

class DSU {
    int n;
    vector<int> p;  // 祖先
    vector<int> r;  // 树高 
public:
    DSU(int _n) : n(_n), p(_n), r(_n, 0) {
        for (int i = 0; i != n; ++i) {
            p[i] = i;
        }
    }

    int find(int x) {
        if (p[x] == x)
            return x;
        return p[x] = find(p[x]); // x的祖先直接设为根节点，路径压缩
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py)
            return false;
        if (r[px] < r[py])  // 低树的作为高树的子树，高树高度不变
            p[px] = py;
        else {
            p[py] = px;
            if (r[px] == r[py])   // 树高相等，默认px为py祖先，且需px高度加1
                r[px]++;
        }
        return true;
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        DSU s(row * col + 2);
        vector<vector<bool>> is_water(row, vector<bool>(col, true));
        vector<pair<int, int>> dxdy{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = row * col;
        for (auto p = cells.rbegin(); p != cells.rend(); ++p) {
            --ans;
            int x = (*p)[0] - 1, y = (*p)[1] - 1;
            is_water[x][y] = false;
            for (const auto& [dx, dy] : dxdy) {
                int i = x + dx, j = y + dy;
                if (0 <= i && i < row && 0 <= j && j < col && !is_water[i][j])
                    s.unite(i * col + j, x * col + y);
            }
            if (x == 0)
                s.unite(x * col + y, row * col);
            else if (x == col - 1)
                s.unite(x * col + y, row * col + 1);
            if (s.find(row * col) == s.find(row * col + 1))
                return ans;
        }
        return -1;
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}
