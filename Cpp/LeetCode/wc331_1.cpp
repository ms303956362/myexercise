#include "usual.h"

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        while (k--) {
            int mx = 0, j = 0;
            for (int i = 0; i < n; ++i) {
                if (gifts[i] > mx) {
                    mx = gifts[i];
                    j = i;
                }
            }
            gifts[j] = sqrt(gifts[j]);
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += gifts[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
