#include "usual.h"

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        if (words[startIndex] == target) {
            return 0;
        }
        int ans = INT_MAX;
        int n = words.size(), d1 = 0, d2 = 0;
        for (int i = 0, idx = startIndex; i < n; ++i, idx = (idx + 1) % n) {
            if (words[idx] == target) {
                ++d1;
            }
        }
        if (d1 > 0) {
            ans = min(ans, d1);
        }
        for (int i = 0, idx = startIndex; i < n; ++i, idx = (idx - 1 + n) % n) {
            if (words[idx] == target) {
                ++d2;
            }
        }
        if (d2 > 0) {
            ans = min(ans, d2);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
