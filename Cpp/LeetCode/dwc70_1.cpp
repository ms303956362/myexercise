#include "usual.h"

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int n = cost.size();
        int ans = 0;
        for (int i = 0; i < n; i += 3) {
            ans += cost[i];
            if (i + 1 < n)
                ans += cost[i + 1];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
