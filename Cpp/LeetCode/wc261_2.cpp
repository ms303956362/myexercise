#include "usual.h"

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for (int i = 0; i < m; ++i)
            sum += rolls[i];
        int res = mean * (n + m) - sum;
        if (!(n <= res && res <= 6 * n))
            return {};
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (i < res % n)
                ans.push_back(res / n + 1);
            else
                ans.push_back(res / n);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
