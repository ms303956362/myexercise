#include "usual.h"

class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<string> s;
        string ans(n - 1, '0');
        dfs(ans, s, n, k);
        return ans;
    }

    void dfs(string& ans, unordered_set<string>& s, int n, int k) {
        int m = ans.size();
        string prefix = ans.substr(m - n + 1, n - 1);
        for (int i = k - 1; i >= 0; --i) {
            prefix.push_back('0' + i);
            if (s.count(prefix) == 0) {
                s.insert(prefix);
                ans.push_back('0' + i);
                dfs(ans, s, n, k);
            }
            prefix.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    int n = 3, k = 3;
    Solution().crackSafe(n, k);
    return 0;
}
