#include "usual.h"

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        vector<int> time(n + 1);
        int m = logs.size(), ans = logs[0][0], max_time = logs[0][1];
        for (int i = 1; i < m; ++i) {
            if (logs[i][1] - logs[i - 1][1] > max_time || logs[i][1] - logs[i - 1][1] == max_time && logs[i][0] < ans) {
                max_time = logs[i][1] - logs[i - 1][1];
                ans = logs[i][0];
            }
        }
        return ans;
    }
};
