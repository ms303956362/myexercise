#include "usual.h"

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int max_sum = 0;
        vector<int> sum(n);
        function<void(int, int)> dfs = [&](int u, int s) {
            s += cost[u];
            if (2 * u + 1 >= n || 2 * u + 2 >= n) {
                max_sum = max(max_sum, s);
                sum[u] = s;
                return;
            }
            dfs(2 * u + 1, s);
            dfs(2 * u + 2, s);
        };
        dfs(0, 0);
        vector<int> op(n);
        int ans = 0;
        for (int i = n / 2; i < n; ++i) {
            op[i] = max_sum - sum[i];
            ans += op[i];
        }
        for (int i = n / 2 - 1; i >= 0; --i) {
            op[i] = min(op[2 * i + 1], op[2 * i + 2]);
            ans -= op[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
