#include "usual.h"

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        // vector<vector<int>> dirs{{0, 1, 0}, {0, -1, 0}, {1, 0, 1}, {-1, 0, 1}};
        // int m = rowCosts.size(), n = colCosts.size();
        // vector<vector<int>> cost(m, vector<int>(n, -1));
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        // q.push({0, startPos[0], startPos[1]});
        // while (!q.empty()) {
        //     auto v = q.top();
        //     q.pop();
        //     int c = v[0], x = v[1], y = v[2];
        //     if (x == homePos[0] && y == homePos[1])
        //         return c;
        //     if (cost[x][y] != -1)
        //         continue;
        //     cost[x][y] = c;
        //     for (const auto& d : dirs) {
        //         int i = x + d[0], j = y + d[1], type = d[2];
        //         if (0 <= i && i < m && 0 <= j && j < n) {
        //             if (type == 1)
        //                 q.push({c + rowCosts[i], i, j});
        //             else
        //                 q.push({c + colCosts[j], i, j});
        //         }
        //     }
        // }
        // return -1;
        int ans = 0;

        for (int i = startPos[0], d = (startPos[0] < homePos[0] ? 1 : -1); i != homePos[0]; i += d) {
            if (i != startPos[0])
                ans += rowCosts[i];
        }
        for (int i = startPos[1], d = (startPos[1] < homePos[1] ? 1 : -1); i != homePos[1]; i += d) {
            if (i != startPos[1])
                ans += colCosts[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
