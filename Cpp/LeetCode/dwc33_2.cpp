#include "usual.h"

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in(n, 0), res;
        for (const auto& e : edges) {
            ++in[e[1]];
        }
        for (int i = 0; i != n; ++i) {
            if (!in[i])
                res.push_back(i);
        }
        return res;
    }
};