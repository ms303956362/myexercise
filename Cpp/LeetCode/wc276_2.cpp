#include "usual.h"

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();
        string curr;
        for (int i = 0; i < n; ++i) {
            curr.push_back(s[i]);
            if (curr.size() >= k) {
                ans.push_back(curr);
                curr.clear();
            }
        }
        if (curr.size() > 0) {
            ans.push_back(curr);
        }
        while (ans.back().size() < k) {
            ans.back().push_back(fill);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
