#include "usual.h"

class ThroneInheritance {
    string kname;
    unordered_set<string> live;
    unordered_map<string, vector<string>> edges;

public:
    ThroneInheritance(string kingName) : kname(kingName) {
        live.insert(kingName);
        edges.insert({kingName, {}});
    }
    
    void birth(string parentName, string childName) {
        edges[parentName].push_back(childName);
        live.insert(childName);
    }
    
    void death(string name) {
        live.erase(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(kname, ans);
        return ans;
    }

    void dfs(const string& u, vector<string>& ans) {
        if (live.count(u) != 0)
            ans.push_back(u);
        for (const auto& v : edges[u]) {
            dfs(v, ans);
        }
    }
};
// [null, null, null, null, null, null, null, ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"], null, ["king", "andy", "matthew", "alex", "asha", "catherine"]]

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

int main(int argc, char const *argv[])
{
    
    return 0;
}
