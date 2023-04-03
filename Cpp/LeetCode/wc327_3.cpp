#include "usual.h"

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> cnt1(26), cnt2(26);
        for (const auto& c : word1) {
            ++cnt1[c - 'a'];
        }
        for (const auto& c : word2) {
            ++cnt2[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] == 0) {
                continue;
            }
            for (int j = 0; j < 26; ++j) {
                if (cnt2[j] == 0) {
                    continue;
                }
                --cnt1[i];
                ++cnt2[i];
                --cnt2[j];
                ++cnt1[j];
                int c1 = 0, c2 = 0;
                for (int k = 0; k < 26; ++k) {
                    if (cnt1[k] > 0) {
                        ++c1;
                    }
                    if (cnt2[k] > 0) {
                        ++c2;
                    }
                }
                if (c1 == c2) {
                    // cout << i << " " << j << " " << c1 << " " << c2 << endl;
                    return true;
                }
                ++cnt2[j];
                --cnt1[j];
                ++cnt1[i];
                --cnt2[i];
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution().isItPossible("abcc", "aab");
    return 0;
}
