#include "usual.h"

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mins;
        for (const auto& log : logs) {
            mins[log[0]].insert(log[1]);
        }
        vector<int> ans(k);
        for (const auto& [id, s]: mins) {
            if (s.size() <= k)
                ++ans[s.size() - 1];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
