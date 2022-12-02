#include "usual.h"

class Solution {
public:
    int buildTransferStation(vector<vector<int>>& area) {
        int m = area.size(), n = area[0].size();
        vector<int> xs, ys;
        for (int i = 0 ; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (area[i][j] == 1) {
                    xs.push_back(i);
                    ys.push_back(j);
                }
            }
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        int xmid = xs[xs.size() / 2], ymid = ys[xs.size() / 2];
        int ans = 0;
        for (int i = 0; i < xs.size(); ++i) {
            ans += abs(xs[i] - xmid) + abs(ys[i] - ymid);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
