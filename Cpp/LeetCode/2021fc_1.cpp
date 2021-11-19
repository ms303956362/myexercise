#include "usual.h"

class Solution {
public:
    int minimumSwitchingTimes(vector<vector<int>>& source, vector<vector<int>>& target) {
        int n = source.size(), m = source[0].size();
        int ans = 0;
        vector<int> cnt1(10005), cnt2(10005);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ++cnt1[source[i][j]];
                ++cnt2[target[i][j]];
            }
        }
        for (int i = 0; i < 10005; ++i) {
            if (cnt1[i] < cnt2[i])
                ans += cnt2[i] - cnt1[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
