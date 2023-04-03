#include "usual.h"

class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            if (forts[i] == 1) {
                int j = i - 1;
                while (j >= 0 && forts[j] == 0) {
                    --j;
                }
                if (j >= 0 && forts[j] == -1) {
                    ans = max(ans, i - j - 1);
                }
                j = i + 1;
                while (j < n && forts[j] == 0) {
                    ++j;
                }
                if (j < n && forts[j] == -1) {
                    ans = max(ans, j - i - 1);
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
