#include "usual.h"
class Point {
public:
    char i;
    char j;
    char val;
    Point(char a=0, char b=0, char v=0) : i(a), j(b), val(v){};
};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int max_dist = -1, dist;
        Point p;
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != n; ++j) {
                vector<vector<char>> vst(n, vector<char>(n, 0));
                queue<Point> q;
                // g[i][j] == 1
                if (grid[i][j] == 1)
                    continue;
                // g[i][j] == 0
                q.push(Point(i, j, 0));
                vst[i][j] = 1;
                dist = -1;  // 初始距离置-1
                while (!q.empty()) {
                    p = q.front();
                    q.pop();
                    if (findLand(p.i-1, p.j, n, p.val, grid, vst, q)) {
                        dist = p.val + 1;
                        break;
                    }
                    if (findLand(p.i+1, p.j, n, p.val, grid, vst, q)) {
                        dist = p.val + 1;
                        break;
                    }
                    if (findLand(p.i, p.j-1, n, p.val, grid, vst, q)) {
                        dist = p.val + 1;
                        break;
                    }
                    if (findLand(p.i, p.j+1, n, p.val, grid, vst, q)) {
                        dist = p.val + 1;
                        break;
                    }
                }
                if (dist > max_dist)
                    max_dist = dist;
            }
        }
        return max_dist;
    }

    bool findLand(int i, int j, int n, int level, vector<vector<int>>& grid, 
                    vector<vector<char>>& vst, queue<Point>& q)
    {
        bool ret = false;
        if (0 <= i && i < n && 0 <= j && j < n) {
            if (grid[i][j] == 1)
                ret = true;
            else if (!vst[i][j]) {
                q.push(Point(i, j, level + 1));
                vst[i][j] = 1;
            }
        }
        return ret;
    }
};

class Solution1 {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<Point> q;
        int n = grid.size();
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != n; ++j) {
                if (grid[i][j]) {
                    q.push(Point(i, j, 0));
                    grid[i][j] = 1; // 已访问
                }
            }
        }
        int dist = -1;
        while (!q.empty()) {
            Point p = q.front();
            q.pop();
            dist = p.val;
            findOcean(p.i - 1, p.j, p.val, grid, q);
            findOcean(p.i + 1, p.j, p.val, grid, q);
            findOcean(p.i, p.j - 1, p.val, grid, q);
            findOcean(p.i, p.j + 1, p.val, grid, q);
        }
        return dist > 0 ? dist : -1;
    }

    void findOcean(int i, int j, int level, vector<vector<int>>& grid, queue<Point>& q) {
        if (0 <= i && i < grid.size() && 0 <= j && j < grid.size()) {
            if (grid[i][j] == 0) {
                q.push(Point(i, j, level + 1));
                grid[i][j] = 1; // 已访问
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> g{{1,0,0},{0,0,0},{0,0,0}};
    Solution1 s;
    int res = s.maxDistance(g);
    cout << res;
    return 0;
}
