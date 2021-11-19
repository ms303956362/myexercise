#include "usual.h"

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size(), cnt = 0;
        if (n % 2)
            return {};
        // sort(changed.begin(), changed.end());
        // for (int i = 0; i < n; ++i)
        // {
        //     if (changed[i] == 0)
        //         ++cnt;
        //     else
        //         break;
        // }
        // if (cnt % 2)
        //     return {};
        // vector<int> ans(cnt / 2, 0);
        // multiset<int> s(changed.begin() + cnt, changed.end());
        // int m = n - cnt;
        // int i = cnt, j = cnt + m / 2;
        // while (!s.empty()) {
        //     auto p = s.begin();
        //     s.erase(p);
        //     if (s.count(*p))
        //         ans.push_back(*p);
        //     else
        // }
        vector<int> ans;
        multiset<int> s(changed.begin(), changed.end());
        while (!s.empty()) {
            auto p = prev(s.end());
            if (*p % 2)
                return {};
            auto q = s.lower_bound(*p / 2);
            if (q != s.end() && *q == *p / 2) {
                ans.push_back(*q);
                s.erase(q);
                s.erase(p);
            } else {
                return {};
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{1, 3, 4, 2, 6, 8};
    Solution().findOriginalArray(a);
    return 0;
}
