#include "usual.h"

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min_d = INT_MAX, ans = -1;
        int n = points.size();
        for (int i = 0; i != n; ++i) {
            if (x == points[i][0] || y == points[i][1]) {
                int d = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (d < min_d) {
                    ans = i;
                    min_d = d;
                }
            }
        }
        return ans;
    }
};