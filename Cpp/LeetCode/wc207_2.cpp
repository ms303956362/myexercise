#include "usual.h"

class Solution {
    int ans;

public:
    int maxUniqueSplit(string s) {
        if (s.size() == 1)
            return 1;
        ans = INT_MIN;
        unordered_set<string> st;
        dfs(0, s, st);
        return ans;
    }

    void dfs(int i, string& s, unordered_set<string> st) {
        if (i == s.size()) {
            ans = max(ans, (int)st.size());
            return;
        }
        for (int j = i + 1; j <= s.size(); ++j) {
            string subs = s.substr(i, j - i);
            if (st.count(subs) == 0) {
                st.insert(subs);
                dfs(j, s, st);
                st.erase(subs);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
