#include "usual.h"

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis1(n, -1), dis2(n, -1);
        int u1 = node1, u2 = node2, step = 0;
        while (dis1[u1] == -1) {
            dis1[u1] = step;
            if (edges[u1] != -1) {
                u1 = edges[u1];
            }
            ++step;
        }
        step = 0;
        while (dis2[u2] == -1) {
            dis2[u2] = step;
            if (edges[u2] != -1) {
                u2 = edges[u2];
            }
            ++step;
        }
        int ans = -1, max_dis = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (dis1[i] == -1 || dis2[i] == -1) {
                continue;
            }
            if (max(dis1[i], dis2[i]) < max_dis) {
                ans = i;
                max_dis = max(dis1[i], dis2[i]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
