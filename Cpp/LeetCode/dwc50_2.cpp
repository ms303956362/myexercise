#include "usual.h"

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = points.size(), m = queries.size();
        vector<int> ans(m, 0);
        for (int j = 0; j != m; ++j) {
            for (int i = 0; i != n; ++i) {
                if ((points[i][0] - queries[j][0]) * (points[i][0] - queries[j][0]) + (points[i][1] - queries[j][1]) * (points[i][1] - queries[j][1]) <= queries[j][2] * queries[j][2])
                    ++ans[j];
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
