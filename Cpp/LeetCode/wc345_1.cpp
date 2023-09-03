#include "usual.h"

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> cnt(n + 1);
        int i = 1, step = 1;
        cnt[i] = 1;
        while (cnt[i] < 2) {
            ++step;
            for (int j = 0; j < k * step; ++j) {
                ++i;
                if (i > n) {
                    i = 1;
                }
            }
            ++cnt[i];
        }
        vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
