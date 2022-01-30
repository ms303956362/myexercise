#include "usual.h"

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1);
        vector<bool> vst(n + 1);
        function<bool(int)> backtrack = [&](int i)
        {
            if (i == 2 * n - 1) {
                return true;
            }
            if (ans[i] != 0) {
                return backtrack(i + 1);
            }
            for (int j = n; j > 0; --j) {
                if (vst[j])
                    continue;
                if (j == 1 || (i + j < 2 * n - 1 && ans[i + j] == 0)) {
                    ans[i] = j;
                    if (j != 1)
                        ans[i + j] = j;
                    vst[j] = true;
                    if (backtrack(i + 1))
                        return true;
                    vst[j] = false;
                    if (j != 1)
                        ans[i + j] = 0;
                    ans[i] = 0;
                }
            }
            return false;
        };
        backtrack(0);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n = 5;
    Solution().constructDistancedSequence(n);
    return 0;
}
