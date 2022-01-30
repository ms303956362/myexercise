#include "usual.h"

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> g;
        unordered_set<string> s(supplies.begin(), supplies.end());
        int n = recipes.size();
        for (int i = 0; i < n; ++i) {
            g[recipes[i]] = ingredients[i];
        }
        vector<string> ans;
        unordered_set<string> vst;
        unordered_map<string, bool> cache;
        function<bool(const string &)> dfs = [&](const string &u)
        {
            if (cache.count(u)) {
                return cache[u];
            }
            if (g[u].size() == 0) {
                cache[u] = (s.count(u) != 0);
                return s.count(u) != 0;
            }
            for (const auto& v : g[u]) {
                if (cache.count(v)) {
                    if (!cache[v]) {
                        return false;
                    }
                } else if (!vst.count(v)) {
                    vst.insert(v);
                    if (!dfs(v)) {
                        cache[v] = false;
                        return false;
                    }
                } else {
                    cache[v] = false;
                    return false;
                }
            }
            cache[u] = true;
            return true;
        };
        for (const auto& r : recipes) {
            vst.clear();
            vst.insert(r);
            if (dfs(r))
                ans.push_back(r);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> s1{"ju", "fzjnm", "x", "e", "zpmcz", "h", "q"};
    vector<vector<string>> s2{{"d"}, { "hveml", "f", "cpivl" }, { "cpivl", "zpmcz", "h", "e", "fzjnm", "ju" }, { "cpivl", "hveml", "zpmcz", "ju", "h" }, { "h", "fzjnm", "e", "q", "x" }, { "d", "hveml", "cpivl", "q", "zpmcz", "ju", "e", "x" }, { "f", "hveml", "cpivl" }};
    vector<string> s3{"f", "hveml", "cpivl", "d"};
    vector<string> a = Solution().findAllRecipes(s1, s2, s3);
    for (const auto& w : a)
        cout << w << " ";
    cout << endl;
    return 0;
}
