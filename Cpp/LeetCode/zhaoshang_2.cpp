#include "usual.h"

class Solution {
public:
    int numFlowers(vector<vector<int>>& roads) {
        int n = roads.size() + 1;
        vector<vector<int>> g(n);
        for (const auto& r : roads) {
            g[r[0]].push_back(r[1]);
            g[r[1]].push_back(r[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (int)g[i].size() + 1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
