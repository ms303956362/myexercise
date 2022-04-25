#include "usual.h"

class Solution {
public:
    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
        int n = cookbooks.size(), ans = -1;
        for (int s = 0; s < (1 << n); ++s) {
            int delicious = 0, fill = 0;
            vector<int> need(5);
            for (int i = 0; i < n; ++i) {
                if (s & (1 << i)) {
                    for (int j = 0; j < 5; ++j) {
                        need[j] += cookbooks[i][j];
                    }
                    delicious += attribute[i][0];
                    fill += attribute[i][1];
                }
            }
            bool ok = true;
            for (int j = 0; j < 5; ++j) {
                if (need[j] > materials[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok && fill >= limit) {
                ans = max(ans, delicious);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
