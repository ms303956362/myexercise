#include "usual.h"

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> e(n);
        vector<bool> vst(n, false);
        for (const auto& t : times) {
            e[t[0] - 1].emplace_back(t[1] - 1, t[2]);
        }
        priority_queue<pair<int, int>> q;
        q.emplace(0, k - 1);
        int ans = 0;
        while (!q.empty()) {
            auto [t, u] = q.top();
            cout << "(" << u << ": " << -t << "):  ";
            if (vst[u]) {
                cout << endl;
                q.pop();
                continue;
            }
            vst[u] = true;
            t = -t;
            // cout << "(" << u << ": " << t << ")  ";
            ans = max(ans, t);
            for (const auto& [v, w] : e[u]) {
                if (!vst[v]) {
                    cout << "(" << v << ": " << t + w << ")  ";
                    q.emplace(- t - w, v);
                }
            }
            cout << endl;
            q.pop();
        }
        cout << endl;
        for (int u = 0; u < n; ++u) {
            if (!vst[u])
                return -1;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v{{3,5,78},{2,1,1},{1,3,0},{4,3,59},{5,3,85},{5,2,22},{2,4,23},{1,4,43},{4,5,75},{5,1,15},{1,5,91},{4,1,16},{3,2,98},{3,4,22},{5,4,31},{1,2,0},{2,5,4},{4,2,51},{3,1,36},{2,3,59}};
    int n = 5, k = 5;
    Solution().networkDelayTime(v, n, k);
    return 0;
}
