#include "usual.h"

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> s1, s2;
        int n = graph.size();
        for (int u = 0; u != n; ++u) {
            for (const auto& v : graph[u]) {
                if (s1.count(u) && s1.count(v) || s2.count(u) && s2.count(v))
                    return false;
                if (s1.count(u))
                    s2.insert(v);
                else {
                    s2.insert(u);
                    s1.insert(v);
                }
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v{{1}, { 0, 3 }, {3}, { 1, 2 }};
    Solution().isBipartite(v);
    return 0;
}
