#include "usual.h"

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = aliceArrows.size();
        int max_score = 0, max_s = 0;
        for (int s = 0; s < (1 << n); ++s) {
            int min_arrows = 0, score = 0;
            for (int i = 0; i < n; ++i) {
                if (s & (1 << i)) {
                    min_arrows += aliceArrows[i] + 1;
                    score += i;
                }
            }
            if (min_arrows > numArrows) {
                continue;
            }
            if (score > max_score) {
                max_score = score;
                max_s = s;
            }
        }
        int rest = numArrows;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (max_s & (1 << i)) {
                ans[i] = aliceArrows[i] + 1;
                rest -= aliceArrows[i] + 1;
            }
        }
        ans[0] += rest;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
