#include "usual.h"

class Solution {
public:
    bool isValidSerialization(string preorder) {
        auto [p, ok] = dfs(0, preorder.size(), preorder);
        return ok;
    }

    pair<int, bool> dfs(int i, int n, const string& s) {
        if (i >= n)
            return {n, false};
        if (s[i] == '#')
            return {i + 1, true};
        int j = i + 1;
        while (j != n && s[j] != ',') {
            ++j;
        }
        auto [next1, leftok] = dfs(j + 1, n, s);
        if (!leftok)
            return {n, false};
        auto [next2, rightok] = dfs(next1 + 1, n, s);
        if (!rightok)
            return {n, false};
        return {next2, true};
    }
};

int main(int argc, char const *argv[])
{
    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    Solution().isValidSerialization(s);
    return 0;
}
  