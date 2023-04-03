#include "usual.h"

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<vector<bool>> is_connected(n, vector<bool>(n));
        for (auto& e : edges) {
            --e[0];
            --e[1];
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            is_connected[e[0]][e[1]] = true;
            is_connected[e[1]][e[0]] = true;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // if (is_connected[i][j])
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
