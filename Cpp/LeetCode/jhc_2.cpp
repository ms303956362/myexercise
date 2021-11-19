#include "usual.h"

class Solution {
public:
    vector<int> analysisHistogram(vector<int>& heights, int cnt) {
        sort(heights.begin(), heights.end());
        // multiset<int> s;
        int n = heights.size();
        // for (int i = 0; i < cnt; ++i) {
        //     s.insert(heights[i]);
        // }
        // int max_diff = *s.rbegin() - *s.begin(), max_i = 0;
        int max_diff = heights[cnt - 1] - heights[0], max_i = 0;
        for (int i = cnt; i < n; ++i) {
            // s.erase(s.lower_bound(heights[i - cnt]));
            // s.insert(heights[i]);

            // if (max_diff > *s.rbegin() - *s.begin()) {
            //     max_diff = *s.rbegin() - *s.begin();
            //     max_i = i - cnt;
            // }
            if (max_diff > heights[i] - heights[i - cnt + 1]) {
                max_diff = heights[i] - heights[i - cnt + 1];
                max_i = i - cnt + 1;
            }
        }
        vector<int> ans(heights.begin() + max_i, heights.begin() + max_i + cnt);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
