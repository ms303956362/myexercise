#include "usual.h"

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        long long ans = 0;
        map<int, int> cnt;
        for (const auto& f : factory) {
            cnt[f[0]] = f[1];
        }
        for (const auto& pos : robot) {
            auto p = cnt.lower_bound(pos), q = p;
            if (p != cnt.begin()) {
                q = prev(p);
            }
            int dis1 = INT_MAX, dis2 = INT_MAX;
            if (p != cnt.end()) {
                dis1 = abs(p->first - pos);
            }
            if (q != cnt.end()) {
                dis2 = abs(q->first - pos);
            }
            if (dis1 < dis2) {
                ans += (long long)abs(p->first - pos);
                --cnt[p->first];
                if (cnt[p->first] == 0) {
                    cnt.erase(p->first);
                }
            } else {
                ans += abs(q->first - pos);
                --cnt[q->first];
                if (cnt[q->first] == 0) {
                    cnt.erase(q->first);
                }
            }
        }
        return ans;
    }
};