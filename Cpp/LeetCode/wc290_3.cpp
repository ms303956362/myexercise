#include "usual.h"

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> recs(101);
        for (const auto& r : rectangles) {
            int l = r[0], h = r[1];
            recs[h].push_back(l);
        }
        for (int i = 0; i <= 100; ++i) {
            sort(recs[i].begin(), recs[i].end());
        }
        vector<int> ans;
        for (const auto& p : points) {
            int cnt = 0;
            for (int y = p[1]; y <= 100; ++y) {
                cnt += recs[y].end() - lower_bound(recs[y].begin(), recs[y].end(), p[0]);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
