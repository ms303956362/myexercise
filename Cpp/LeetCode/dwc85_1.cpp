#include "usual.h"

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), ans = k;
        for (int i = 0; i <= n - k; ++i) {
            int cnt = 0;
            for (int j = i; j < i + k; ++j) {
                if (blocks[j] == 'W') {
                    ++cnt;
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
