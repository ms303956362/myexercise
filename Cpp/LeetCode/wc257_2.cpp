#include "usual.h"

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        map<int, unordered_set<int>> a;
        for (const auto& p : properties) {
            a[p[0]].insert(p[1]);
        }
        int max_p = INT_MIN, ans = 0;
        for (auto p = a.rbegin(); p != a.rbegin(); ++p) {
            int max_pp = INT_MIN;
            for (const auto& num : p->second) {
                max_pp = max(max_pp, num);
                if (max_p > num)
                    ++ans;
            }
            max_p = max(max_p, max_pp);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v{{ 1, 1 }, { 2, 1 }, { 2, 2 }, { 1, 2 }};
    Solution().numberOfWeakCharacters(v);
    return 0;
}
