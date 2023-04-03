#include "usual.h"

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pre(n + 1);
        set<char> st{'a','e','i','o', 'u'};
        for (int i = n - 1; i >= 0; --i) {
            pre[i] = pre[i + 1];
            if (st.count(words[i].front()) && st.count(words[i].back())) {
                ++pre[i];
            }
        }
        vector<int> ans;
        for (const auto& q : queries) {
            ans.push_back(pre[q[0]] - pre[q[1] + 1]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
