#include "usual.h"

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> edges;
        for (const auto& e : adjacentPairs) {
            edges[e[0]].push_back(e[1]);
            edges[e[1]].push_back(e[0]);
        }
        vector<int> terminals;
        for (const auto& [i, v] : edges) {
            if (v.size() == 1)
                terminals.push_back(i);
        }
        vector<int> ans{terminals[0]};
        int last = terminals[0], now = edges[terminals[0]][0];
        while (now != terminals[1]) {
            ans.push_back(now);
            int next1 = edges[now][0], next2 = edges[now][1];
            if (next1 != last) {
                last = now;
                now = next1;
            } else {
                last = now;
                now = next2;
            }
        }
        ans.push_back(terminals[1]);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
