#include "usual.h"

class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        int MOD = 1e9 + 7;
        hc.push_back(h);
        vc.push_back(w);
        int max_h = hc[0], max_w = vc[0];
        for (int i = 1; i != hc.size(); ++i) {
            max_h = max(max_h, hc[i] - hc[i - 1]);
        }
        for (int i = 1; i != vc.size(); ++i) {
            max_w = max(max_w, vc[i] - vc[i - 1]);
        }
        long long max_a = (long long)max_h * (long long)max_w;
        return max_a % MOD;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}