#include "usual.h"

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        string ans;
        int i, j;
        while (i < n && j < m) {
            if (word1.substr(i) > word2.substr(j))
                ans.push_back(word1[i++]);
            else
                ans.push_back(word2[j++]);
        }
        while (i < n)
            ans.push_back(word1[i++]);
        while (j < m)
            ans.push_back(word2[j++]);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s1("cabaa"), s2("bcaaa");
    Solution().largestMerge(s1, s2);
    return 0;
}
