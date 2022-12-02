#include "usual.h"

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = capacity[i] - rocks[i];
        }
        sort(diff.begin(), diff.end());
        int ans = 0;
        for (int i = 0; i < n && additionalRocks >= 0; ++i) {
            if (additionalRocks >= diff[i]) {
                ++ans;
                additionalRocks -= diff[i];
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
