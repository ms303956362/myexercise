#include "usual.h"

class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(), cards.end());
        int ans = 0, n = cards.size();
        vector<int> odd, even;
        for (int i = 0; i < cnt; ++i) {
            if (cards[n - i - 1] % 2)
                odd.push_back(cards[n - i - 1]);
            else
                even.push_back(cards[n - i - 1]);
            ans += cards[i];
        }
        if (odd.size() % 2 == 0)
            return ans;
        int ans1 = 0, ans2 = 0;
        if (!even.empty()) {
            for (int i = n - cnt - 1; i >= 0; --i) {
                if (cards[i] % 2 == 1) {
                    ans1 = ans + cards[i] - even.back();
                    break;
                }
            }
        }
        if (!odd.empty()) {
            for (int i = n - cnt - 1; i >= 0; --i) {
                if (cards[i] % 2 == 0) {
                    ans2 = ans + cards[i] - odd.back();
                    break;
                }
            }
        }
        return max(ans1, ans2);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{1, 2, 8, 9};
    int cnt = 3;
    Solution().maxmiumScore(a, cnt);
    return 0;
}
