#include "usual.h"

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n = queries[0].size();
        for (const auto& s : queries) {
            for (const auto& t : dictionary) {
                int cnt = 0;
                for (int i = 0; i < n; ++i) {
                    if (s[i] != t[i]) {
                        ++cnt;
                    }
                }
                if (cnt <= 2) {
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
