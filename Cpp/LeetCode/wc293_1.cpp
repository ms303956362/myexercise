#include "usual.h"

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans{words[0]};
        sort(words[0].begin(), words[0].end());
        for (int i = 1; i < n; ++i) {
            string tmp = words[i];
            sort(words[i].begin(), words[i].end());
            if (words[i] != words[i - 1]) {
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
