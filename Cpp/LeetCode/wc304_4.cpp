#include "usual.h"

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vst(n, false);
        int ans = -1;
        for (int u = 0; u < n; ++u) {
            if (!vst[u]) {
                ans = max(ans, walk(u, edges, vst));
            }
        }
        return ans;
    }

    int walk(int u, vector<int>& edges, vector<bool>& vst) {
        unordered_map<int, int> path;
        int step = 0;
        while (!vst[u]) {
            if (edges[u] == -1) {
                return -1;
            }
            path[u] = step;
            vst[u] = true;
            u = edges[u];
            ++step;
        }
        return path.count(u) ? (step - path[u]) : -1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
