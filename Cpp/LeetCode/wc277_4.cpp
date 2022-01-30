#include "usual.h"

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        auto check = [&](int s)
        {
            vector<bool> is_good(n);
            for (int i = 0; i < n; ++i) {
                is_good[i] = (s & 1);
                s >>= 1;
            }
            for (int i = 0; i < n; ++i) {
                if (!is_good[i])
                    continue;
                for (int j = 0; j < n; ++j) {
                    if (statements[i][j] == 1 && !is_good[j]) {
                        return false;
                    } else if (statements[i][j] == 0 && is_good[j]) {
                        return false;
                    }
                }
            }
            return true;
        };
        int ans = 0;
        for (int s = 0; s < (1 << n); ++s) {
            int cnt = 0, tmp = s;
            for (int i = 0; i < n; ++i) {
                if (tmp & 1) {
                    ++cnt;
                }
                tmp >>= 1;
            }
            if (check(s)) {
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
