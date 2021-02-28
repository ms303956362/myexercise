#include "usual.h"

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        vector<int> cache(1 << maxChoosableInteger);
        return dfs(0, 0, maxChoosableInteger, desiredTotal, cache);
    }

    bool dfs(int s, int sum, int maxChoosableInteger, int desiredTotal, vector<int>& cache) {
        if (cache[s] != 0)
            return cache[s] == 1;
        bool ret = false;
        for (int i = 0; i != maxChoosableInteger; ++i) {
            if (!((s >> i) & 1) == 0) {
                s |= (1 << i);
                if (sum + i + 1 >= desiredTotal)
                    ret = true;
                else
                    ret = !dfs(s, sum + i + 1, maxChoosableInteger, desiredTotal, cache);
                s &= ~(1 << i);
                if (ret)
                    break;
            }
        }
        cache[s] = ret;
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    int m = 11, d = 10;
    Solution().canIWin(m, d);
    return 0;
}
