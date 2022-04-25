#include "usual.h"

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 != 0)
            return {};
        vector<long long> ans;
        long long res = finalSum;
        for (int i = 2; i <= res; i += 2) {
            ans.push_back(i);
            res -= i;
        }
        if (res > 0) {
            if (ans.empty()) {
                ans.push_back(res);
            } else {
                ans.back() += res;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution().maximumEvenSplit(12);
    return 0;
}
