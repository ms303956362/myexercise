#include "usual.h"

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> cnt1, cnt2;
        for (const auto& w : words1) {
            if (!cnt1.count(w))
                cnt1[w] = 0;
            ++cnt1[w];
        }
        for (const auto& w : words2) {
            if (!cnt2.count(w))
                cnt2[w] = 0;
            ++cnt2[w];
        }
        int ans = 0;
        for (const auto& w : words1) {
            if (cnt1[w] == 1 && cnt2[w] == 1)
                ++ans;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
