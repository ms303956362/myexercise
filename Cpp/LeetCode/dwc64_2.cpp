#include "usual.h"

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        map<int, int> max_r;
        int max_val = 0;
        for (int i = n - 1; i >= 0; --i) {
            max_val = max(max_val, events[i][2]);
            max_r[events[i][0]] = max_val;
        }
        int ans = 0;
        for (const auto& e : events) {
            auto p = max_r.lower_bound(e[1] + 1);
            if (p != max_r.end()) {
                ans = max(ans, p->second + e[2]);
            } else {
                ans = max(ans, e[2]);
            }
        }
        return ans;
    }
};

