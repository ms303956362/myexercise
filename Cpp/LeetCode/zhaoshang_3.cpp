#include "usual.h"

class Solution {
public:
    vector<int> lightSticks(int height, int width, vector<int>& indices) {
        int n = (height + 1) * (width + 1);
        vector<vector<int>> g(n);
        vector<vector<bool>> is_connected(n, vector<bool>(n, true));
        int period = 2 * width + 1;
        for (const auto& index : indices) {
            int row = index / period, col = index % period, start = row * (width + 1);
            if (0 <= col && col < width) {
                is_connected[start + col][start + col + 1] = false;
            } else {
                is_connected[start + col - width][start + col + 1] = false;
            }
        }
        unordered_set<int> vs;
        for (int i = 0; i < n; ++i) {
            if ((i + 1) / (width + 1) == i / (width + 1) && is_connected[i][i + 1]) {
                g[i].push_back(i + 1);
                g[i + 1].push_back(i);
                vs.insert(i);
                vs.insert(i + 1);
            }
            if (i + width + 1 < n && is_connected[i][i + width+ 1]) {
                g[i].push_back(i + width+ 1);
                g[i + width+ 1].push_back(i);
                vs.insert(i);
                vs.insert(i + width+ 1);
            }
        }
        auto bfs = [&](int start)
        {
            vector<bool> vst(n);
            queue<int> q;
            int ans = 0, cnt = 0;
            q.push(start);
            vst[start] = true;
            while (!q.empty()) {
                int l = q.size();
                ++ans;
                for (int i = 0; i < l; ++i) {
                    auto u = q.front();
                    q.pop();
                    ++cnt;
                    for (const auto& v : g[u]) {
                        if (!vst[v]) {
                            vst[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
            return cnt == vs.size() ? ans : -1;
        };
        vector<int> dis(n);
        int min_dis = INT_MAX;
        for (const auto& i : vs) {
            int ret = bfs(i);
            if (ret == -1) {
                return {};
            }
            dis[i] = ret;
            min_dis = min(min_dis, ret);
        }
        vector<int> ans;
        for (const auto& i : vs) {
            if (dis[i] == min_dis) {
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int h = 2, w = 2;
    vector<int> is{2, 5, 6, 7, 8, 10, 11};
    Solution().lightSticks(h, w, is);
    return 0;
}
