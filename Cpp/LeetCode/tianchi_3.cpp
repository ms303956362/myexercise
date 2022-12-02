#include "usual.h"

class Solution {
public:
    vector<int> arrangeBookshelf(vector<int>& order, int limit) {
        int n = order.size();
        unordered_map<int, int> cnt, cnt1;
        for (int i = n - 1; i >= 0; --i) {
            ++cnt[order[i]];
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (cnt1[order[i]] < limit) {
                while (!ans.empty() && order[i] < ans.back() && (cnt[ans.back()] + cnt1[ans.back()]) > limit) {
                    --cnt1[ans.back()];
                    ans.pop_back();
                }
                ++cnt1[order[i]];
                ans.push_back(order[i]);
            }
            --cnt[order[i]];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{3,4,5,4,6,5,4,7,8};
    int l = 1;
    Solution().arrangeBookshelf(v, l);
    return 0;
}
