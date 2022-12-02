#include "usual.h"

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        vector<int> pre(n + 1), start(n);
        for (int i = n - 1; i >= 0; --i) {
            start[i] = tiles[i][0];
            pre[i] = pre[i + 1] + (tiles[i][1] - tiles[i][0] + 1);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = lower_bound(start.begin() + i, start.end(), start[i] + carpetLen) - start.begin() - 1;
            ans = max(ans, pre[i] - pre[j] + min(tiles[j][1] - tiles[j][0] + 1, tiles[i][0] + carpetLen - tiles[j][0]));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    // vector<vector<int>> a{{ 1, 5 }, { 10, 11 }, { 12, 18 }, { 20, 25 }, { 30, 32 }};
    // int l = 10;
    vector<vector<int>> a{{10, 11}, {1, 1}};
    int l = 2;
    Solution().maximumWhiteTiles(a, l);
    return 0;
}
