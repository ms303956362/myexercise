#include "usual.h"


class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if (N < 10)
            return N;
        vector<int> vd;
        while (N) {
            vd.push_back(N % 10);
            N /= 10;
        }
        int ans = 0;
        int n = vd.size();
        if (vd[n - 2] == 0 && vd[n - 1] == 1) {
            for (int i = 0; i != n - 1; ++i)
                ans = ans * 10 + 9;
            return ans;
        }
        int i;
        vector<pair<int, int>> vp;
        vp.emplace_back(vd[n - 1], 1);
        for (i = n - 2; i >= 1; --i) {
            if (vd[i] != vp.back().first)
                vp.emplace_back(vd[i], 1);
            else {
                ++vp.back().second;
            }
            if (vd[i] > vd[i - 1])
                break;
        }
        if (vp.back().first <= vd[i]) {
            for (auto& [n, cnt] : vp) {
                for (int j = 0; j != cnt; ++j) {
                    ans = 10 * ans + n;
                }
            }
            ans = ans * 10 + vd[0];
        }
        else {
            for (int k = 0; k != vp.size() - 1; ++k) {
                auto& [n, cnt] = vp[k];
                for (int j = 0; j != cnt; ++j) {
                    ans = 10 * ans + n;
                }
            }
            auto& [n, cnt] = vp.back();
            ans = 10 * ans + n - 1;
            for (int j = 0; j != cnt - 1 + i; ++j) {
                ans = 10 * ans + 9;
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    int N = 20;
    Solution().monotoneIncreasingDigits(N);
    return 0;
}
