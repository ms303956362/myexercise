#include "usual.h"

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> pre(n), suf(n);
        stack<pair<int, int>> st;
        st.emplace(0, 0);
        long long total = maxHeights[0];
        for (int i = 1; i < n; ++i) {
            int k = i;
            while (!st.empty() && maxHeights[st.top().first] >= maxHeights[i]) {
                total -= (long long)(k - st.top().second) * (long long)(maxHeights[st.top().first] - maxHeights[i]);
                k = st.top().second;
                st.pop();
            }
            pre[i] = total;
            total += maxHeights[i];
            st.emplace(i, k);
        }
        while (!st.empty()) {
            st.pop();
        }
        st.emplace(n - 1, n - 1);
        total = maxHeights[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            int k = i;
            while (!st.empty() && maxHeights[st.top().first] >= maxHeights[i]) {
                total -= (long long)(st.top().second - k) * (long long)(maxHeights[st.top().first] - maxHeights[i]);
                k = st.top().second;
                st.pop();
            }
            suf[i] = total;
            total += maxHeights[i];
            st.emplace(i, k);
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, pre[i] + suf[i] + maxHeights[i]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
