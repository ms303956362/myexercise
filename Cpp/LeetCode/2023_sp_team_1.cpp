#include "usual.h"

class Solution {
public:
    int runeReserve(vector<int>& runes) {
        int n = runes.size();
        sort(runes.begin(), runes.end());
        int ans = 1, cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (runes[i] - runes[i - 1] <= 1) {
                ++cnt;
            } else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
