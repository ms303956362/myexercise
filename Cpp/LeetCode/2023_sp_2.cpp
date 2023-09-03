#include "usual.h"

class Solution {
public:
    int adventureCamp(vector<string>& expeditions) {
        unordered_set<string> known;
        int ans = -1, max_new = 0, m = expeditions.size();
        for (int k = 0; k < m; ++k) {
            string s = expeditions[k];
            unordered_set<string> st;
            int i = 0, n = s.size();
            while (i < n) {
                int j = i;
                while (j < n && s[j] != '-') {
                    ++j;
                }
                string name = s.substr(i, j - i);
                if (!known.count(name)) {
                    st.insert(name);
                }
                if (j < n) {
                    j += 2;
                }
                i = j;
            }
            if (k > 0 && st.size() > max_new) {
                max_new = st.size();
                ans = k;
            }
            for (const auto& name : st) {
                known.insert(name);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
