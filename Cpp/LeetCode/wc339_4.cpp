#include "usual.h"

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> ans(n, -1);
        set<int> st;
        for (int i = 0; i < n; ++i) {
            st.insert(i);
        }
        for (const auto& i : banned) {
            st.erase(i);
        }
        queue<int> q;
        st.erase(p);
        q.push(p);
        int step = 0;
        while (!q.empty()) {
            int l = q.size();
            while (l--) {
                auto u = q.front();
                q.pop();
                ans[u] = step;
                auto ptr = st.lower_bound(max(u - k + 1, k - 1 - u));
                if (ptr != st.end() && abs(u - *ptr) % 2 == k % 2) {
                    ptr = next(ptr);
                }
                // while (ptr != st.end() && *ptr <= min(u + k - 1, 2 * (n - 1) - (k - 1 + u))) {
                while (ptr != st.end() && *ptr <= min(u + k - 1, n - 1 - (k - 1 - (n - 1 - u)))) {
                    q.push(*ptr);
                    auto tmp = ptr;
                    ptr = next(ptr);
                    st.erase(tmp);
                    if (ptr != st.end() && abs(u - *ptr) % 2 == k % 2) {
                        ptr = next(ptr);
                    }
                }
            }
            ++step;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n = 4;
    int p = 2;
    vector<int> banned{};
    int k = 2;
    Solution().minReverseOperations(n, p, banned, k);
    return 0;
}

// [0,-1,-1,1]
// [0,-1,-1,-1,-1]
// [-1,-1,0,-1]
// [0,1,2,3,4]
// [0,-1,-1,1]
// [2,1,0,1]
// [0,3,2,1,4]