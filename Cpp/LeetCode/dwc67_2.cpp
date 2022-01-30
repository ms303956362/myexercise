#include "usual.h"

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> ldown(n), rup(n);
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (security[i - 1] >= security[i]) {
                ++cnt;
            } else {
                cnt = 0;
            }
            ldown[i] = cnt;
        }
        cnt = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (security[i] <= security[i + 1]) {
                ++cnt;
            } else {
                cnt = 0;
            }
            rup[i] = cnt;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (ldown[i] >= time && rup[i] >= time)
                ans.push_back(i);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
