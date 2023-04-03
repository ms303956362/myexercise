#include "usual.h"

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> cnt(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            int j = upper_bound(prizePositions.begin(), prizePositions.end(), prizePositions[i] + k) - prizePositions.begin();
            cnt[i] = max(cnt[j + 1], j - i);
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            int j = upper_bound(prizePositions.begin(), prizePositions.end(), prizePositions[i] + k) - prizePositions.begin();
            ans = max(ans, j - i + cnt[j]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
