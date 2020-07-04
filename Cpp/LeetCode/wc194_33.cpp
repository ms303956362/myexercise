#include "usual.h"

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        set<int> q;
        unordered_map<int, int> s;
        vector<int> res(n, -1);
        for (int i = 0; i != n; ++i) {
            if (rains[i] == 0) {
                q.insert(i);
            } else {
                auto p = s.find(rains[i]);
                if (p == s.end()) {
                    s.insert({rains[i], i});
                } else {
                    if (q.empty()) {
                        return {};
                    } else {
                        auto pt = q.lower_bound(p->second);
                        if (pt == q.end()) {
                            return {};
                        } else {
                            res[*pt] = rains[i];
                            q.erase(pt);
                        }
                        p->second = i;
                    }
                }
            }
        }
        int k = 1;
        for (; k != INT_MAX; ++k) {
            auto p = s.find(k);
            if (p == s.end())
                break;
        }
        for (auto p = q.begin(); p != q.end(); ++p) {
            res[*p] = k;
        }
        return res;
    }
};