#include "usual.h"

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> a;
        int n = plantTime.size();
        for (int i = 0; i < n; ++i) {
            a.emplace_back(growTime[i], plantTime[i]);
        }
        sort(a.begin(), a.end());
        int ans = 0, sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            sum += a[i].second;
            ans = max(ans, sum + a[i].first);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{1, 2, 3, 2}, b{2, 1, 2, 1};
    Solution().earliestFullBloom(a, b);
    return 0;
}
