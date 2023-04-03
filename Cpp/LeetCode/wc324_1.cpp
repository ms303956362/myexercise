#include "usual.h"

class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size();
        auto check = [&](int i, int j) {
            vector<bool> has1(26), has2(26);
            for (const auto& c : words[i]) {
                has1[c - 'a'] = true;
            }
            for (const auto& c : words[j]) {
                has2[c - 'a'] = true;
            }
            return has1 == has2;
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (check(i, j)) {
                    ++ans;
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
