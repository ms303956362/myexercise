#include "usual.h"

class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size(), n = mat[0].size();
        int ans = 0;
        for (int s = 0; s < (1 << n); ++s) {
            if (__builtin_popcount(s) == cols) {
                int cnt = 0;
                for (int i = 0; i < m; ++i) {
                    bool ok = true;
                    for (int j = 0; j < n; ++j) {
                        if (mat[i][j] == 1 && (s & (1 << j)) == 0) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        ++cnt;
                    }
                }
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
