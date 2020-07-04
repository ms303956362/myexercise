#include "usual.h"

class Solution {
public:
    bool isPathCrossing(string path) {
        vector<vector<int>> cache;
        vector<int> p(2, 0);
        cache.push_back(p);
        for (auto d : path) {
            switch (d) {
            case 'N':
                ++p[1];
                break;
            case 'S':
                --p[1];
                break;
            case 'E':
                ++p[0];
                break;
            case 'W':
                --p[0];
                break;
            }
            for (const auto& q : cache) {
                if (q[0] == p[0] && q[1] == p[1])
                    return false;
            }
            cache.push_back(p);
        }
        return true;
    }
};