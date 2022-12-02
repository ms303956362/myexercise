#include "usual.h"


class Solution {
public:
    int beautifulBouquet(vector<int>& flowers, int c) {
        int n = flowers.size();
        vector<int> cnt(100005);
        int i = n - 1, j = n - 1;
        int ans = 0, mod = 1e9 + 7;
        while (i >= 0) {
            ++cnt[flowers[i]];
            while (j >= i && cnt[flowers[i]] > c) {
                --cnt[flowers[j]];
                --j;
            }
            ans = (ans + j - i + 1) % mod;
            --i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
