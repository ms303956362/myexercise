#include "usual.h"

class Solution {
public:
    int getLength(vector<string>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        int x = 0, y = 0, dx = 1, dy = 0;
        while (0 <= x && x < m && 0 <= y && y < n) {
            if (grid[x][y] == 'L') {
                swap(dx, dy);
            } else if (grid[x][y] == 'R') {
                swap(dx, dy);
                dx = -dx;
                dy = -dy;
            }
            ++ans;
            x += dx;
            y += dy;
        }
        return ans;
    }
};