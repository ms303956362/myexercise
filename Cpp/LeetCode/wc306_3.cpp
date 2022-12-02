#include "usual.h"

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string curr, ans = "999999999";
        function<bool()> check = [&]() {
            for (int i = 0; i < n; ++i) {
                if (pattern[i] == 'I' && curr[i + 1] < curr[i]) {
                    return false;
                }
                if (pattern[i] == 'D' && curr[i + 1] > curr[i]) {
                    return false;
                }
            }
            return true;
        };
        vector<bool> vst(10);
        function<void(int)> backtrack = [&](int i) {
            if (i == n + 1) {
                if (check() && curr < ans) {
                    ans = curr;
                }
                return;
            }
            for (int j = 1; j <= 9; ++j) {
                if (!vst[j]) {
                    vst[j] = true;
                    curr.push_back(j + '0');
                    backtrack(i + 1);
                    curr.pop_back();
                    vst[j] = false;
                }
            }
        };
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
