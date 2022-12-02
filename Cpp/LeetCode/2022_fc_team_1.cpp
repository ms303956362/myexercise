#include "usual.h"

class Solution {
public:
    int minNumBooths(vector<string>& demand) {
        int m = demand.size();
        vector<int> max_cnt(26);
        for (int i = 0; i < m; ++i) {
            int n = demand[i].size();
            vector<int> cnt(26);
            for (int j = 0; j < n; ++j) {
                ++cnt[demand[i][j] - 'a'];
            }
            for (int k = 0; k < 26; ++k) {
                max_cnt[k] = max(max_cnt[k], cnt[k]);
            }
        }
        int ans = 0;
        for (int k = 0; k < 26; ++k) {
            ans += max_cnt[k];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
