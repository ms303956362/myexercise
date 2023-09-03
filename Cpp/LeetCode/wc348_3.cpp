#include "usual.h"

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long cntr = 0, cntc = 0, ans = 0;
        reverse(queries.begin(), queries.end());
        vector<bool> hasr(n + 1), hasc(n + 1);
        for (const auto& q: queries) {
            if (q[0] == 0) {
                if (!hasr[q[1]]) {
                    ans += ((long long)n - cntc) * (long long)q[2];
                    ++cntr;
                    hasr[q[1]] = true;
                }
            } else {
                if (!hasc[q[1]]) {
                    ans += ((long long)n - cntr) * (long long)q[2];
                    ++cntc;
                    hasc[q[1]] = true;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
