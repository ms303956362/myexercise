#include "usual.h"

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        map<int, int> m;
        int max_beauty = 0;
        sort(items.begin(), items.end());
        for (const auto& item : items) {
            max_beauty = max(max_beauty, item[1]);
            m[item[0]] = max_beauty;
        }
        vector<int> ans;
        for (const auto& q : queries) {
            if (m.upper_bound(q) == m.begin())
                ans.push_back(0);
            else
                ans.push_back(prev(m.upper_bound(q))->second);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
