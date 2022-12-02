#include "usual.h"

class Solution {
public:
    int minSwaps(vector<int>& chess) {
        int n = chess.size();
        vector<int> pre(n + 1);
        int l = 0;
        for (int i = n - 1; i >= 0; --i) {
            l += chess[i];
            pre[i] = pre[i + 1] + chess[i];
        }
        int ans = n;
        for (int i = 0; i <= n - l; ++i) {
            int sum = pre[i] - pre[i + l];
            ans = min(ans, l - sum);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
