#include "usual.h"

class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size() / 2;
        vector<vector<bool>> has(10, vector<bool>(3, false));
        for (int i = 0; i < 2 * n; i += 2) {
            if (rings[i] == 'R') {
                has[rings[i + 1] - '0'][0] = true;
            } else if (rings[i] == 'G') {
                has[rings[i + 1] - '0'][1] = true;
            } else {
                has[rings[i + 1] - '0'][2] = true;
            }
        }
        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            if (has[i][0] && has[i][1] && has[i][2])
                ++ans;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
