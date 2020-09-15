#include "usual.h"

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                if (mat[i][j]) {
                    bool ok = true;
                    for (int p = 0; p != n; ++p) {
                        if (p == i || mat[p][j] == 0)
                            continue;
                        ok = false;
                        break;
                    }
                    if (!ok)
                        break;
                    for (int p = 0; p != m; ++p) {
                        if (p == j || mat[i][p] == 0)
                            continue;
                        ok = false;
                        break;
                    }
                    if (!ok)
                        break;
                    ++ans;
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
