#include "usual.h"

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> cnt0(n + 1, 0), cnt1(n + 1, 0);
        for (int i = 1; i != n + 1; ++i) {
            if (s[i - 1] == '0')
                cnt0[i] = cnt0[i - 1] + 1;
            else
                cnt0[i] = cnt0[i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1')
                cnt1[i] = cnt1[i + 1] + 1;
            else
                cnt1[i] = cnt1[i + 1];
        }
        int max_cnt = 0;
        for (int i = 1; i != n; ++i) {
            if (cnt1[i] + cnt0[i] > max_cnt)
                max_cnt = cnt1[i] + cnt0[i];
        }
        return max_cnt;
    }
};

int main(int argc, char const *argv[])
{
    Solution().maxScore("00");
    return 0;
}
