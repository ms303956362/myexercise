#include "usual.h"

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> in(n + 1, 0), out(n + 1, 0);
        vector<vector<int>> e(n + 1, vector<int>());
        for (const auto& d : dependencies) {
            e[d[0]].push_back(d[1]);
            ++in[d[1]];
            ++out[d[0]];
        }
        int res = 0;
        while (true) {
            vector<int> cand;
            for (int i = 1; i <= n; ++i) {
                if (in[i] == 0)
                    cand.push_back(i);
            }
            if (cand.size() == 0)
                return res;
            ++res;
            if (cand.size() <= k) {
                for (auto v :cand) {
                    for (auto u : e[v]) {
                        --in[u];
                    }
                    out[v] = -1;
                    in[v] = -1;
                }
            } else {
                for (int i = 0; i != k; ++i) {
                    int max_out = INT_MIN, max_v, max_j = 0;
                    for (int j = 0; j != cand.size(); ++j)
                    {
                        int v = cand[j];
                        if (max_out < out[v]) {
                            max_v = v;
                            max_out = out[v];
                            max_j = j;
                        }
                    }
                    for (auto max_v :cand) {
                        for (auto u : e[max_v]) {
                            --in[u];
                        }
                        out[max_v] = -1;
                        in[max_v] = -1;
                    }
                    cand.erase(cand.begin() + max_j);
                }
            }
        }
        return res;
    }
};