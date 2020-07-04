#include "usual.h"

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        queue<int> q;
        unordered_map<int, int> s;
        vector<int> res(n, -1);
        for (int i = 0; i != n; ++i) {
            if (rains[i] == 0) {
                q.push(i);
            } else {
                auto p = s.find(rains[i]);
                if (p == s.end()) {
                    s.insert({rains[i], i});
                } else {
                    if (q.empty()) {
                        return {};
                    } else {
                        int j = q.front();
                        res[j] = rains[i];
                        q.pop();
                    }
                }
            }
        }
        int k = 0;
        for (; k != INT_MAX; ++k) {
            auto p = s.find(k);
            if (p == s.end())
                break;
        }
        while (!q.empty()) {
            int j = q.front();
            res[j] = k;
            q.pop();
        }
        return res;
    }
};