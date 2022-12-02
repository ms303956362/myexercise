#include "usual.h"

int has[8];

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int ans = 0x3f3f3f3f;
        memset(has, 0, sizeof(int) * 8);
        function<void(int)> dfs = [&](int i)
        {
            if (i == n)
            {
                int max_has = 0;
                for (int j = 0; j < k; ++j)
                {
                    max_has = max(max_has, has[j]);
                }
                ans = min(ans, max_has);
                return;
            }
            for (int j = 0; j < k; ++j)
            {
                has[j] += cookies[i];
                dfs(i + 1);
                has[j] -= cookies[i];
            }
        };
        dfs(0);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
