#include "usual.h"

class Solution {
public:
    string evolutionaryRecord(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> g(n);
        int root = 0;
        for (int i = 0; i < n; ++i) {
            if (parents[i] != -1) {
                g[parents[i]].push_back(i);
            } else {
                root = i;
            }
        }
        function<string(int, int)> dfs = [&](int u, int f) -> string {
            vector<string> vt;
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                string s = dfs(v, u);
                s.push_back('1');
                vt.push_back(s);
            }
            sort(vt.begin(), vt.end());
            string ret = "0";
            for (const auto& s : vt) {
                ret += s;
            }
            return ret;
        };
        string ans = dfs(root, -1);
        while (ans.back() == '1') {
            ans.pop_back();
        }
        return ans.substr(1);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> p{-1,0,0,2};
    Solution().evolutionaryRecord(p);
    return 0;
}
