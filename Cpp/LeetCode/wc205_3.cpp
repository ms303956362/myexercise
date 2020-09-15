#include "usual.h"

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0;
        int n = s.size(), i = 0, j = i + 1;
        while (i < n) {
            int sum = cost[i], maxc = cost[i];
            for (j = i + 1; j < n && s[j] == s[i]; ++j) {
                maxc = max(maxc, cost[j]);
                sum += cost[j];
            }
            ans += sum - maxc;
            i = j;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
