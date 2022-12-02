#include "usual.h"

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int ans = max(special[0] - bottom, top - special.back());
        int n = special.size();
        for (int i = 1; i < n; ++i) {
            ans = max(ans, special[i] - special[i - 1] - 1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
