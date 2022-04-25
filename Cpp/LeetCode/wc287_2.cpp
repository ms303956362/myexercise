#include "usual.h"

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> gamers;
        unordered_map<int, int> times;
        for (const auto& m : matches) {
            gamers.insert(m[0]);
            gamers.insert(m[1]);
            if (!times.count(m[1])) {
                times[m[1]] = 0;
            }
            ++times[m[1]];
        }
        vector<vector<int>> ans(2);
        for (const auto& g : gamers) {
            if (times[g] == 0) {
                ans[0].push_back(g);
            } else if (times[g] == 1) {
                ans[1].push_back(g);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
