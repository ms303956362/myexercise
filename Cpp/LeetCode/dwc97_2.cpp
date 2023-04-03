#include "usual.h"

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        long long sum = 0, ans = 0;
        set<long long> st(banned.begin(), banned.end());
        for (long long i = 1; i <= n; ++i) {
            if (st.count(i)) {
                continue;
            }
            sum += i;
            if (sum > maxSum) {
                break;
            }
            ++ans;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
