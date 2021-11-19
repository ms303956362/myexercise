#include "usual.h"

class Solution {
    int min_times;
    vector<int> min_path;

public:
    vector<int> metroRouteDesignI(vector<vector<int>>& lines, int start, int end) {
        if (start == end) {
            return {start};
        }
        vector<vector<pair<int, int>>> g(10005, vector<pair<int, int>>());
        for (int j = 0; j < lines.size(); ++j) {
            int n = lines[j].size();
            for (int i = 0; i < n; ++i) {
                if (i - 1 >= 0) {
                    g[lines[j][i]].emplace_back(lines[j][i - 1], j);
                }
                if (i + 1 < n) {
                    g[lines[j][i]].emplace_back(lines[j][i + 1], j);
                }
            }
        }
        min_times = INT_MAX;
        min_path.clear();
        vector<int> path;
        vector<bool> vst(10005);
        dfs(start, end, -1, -1, path, vst, g);
        return min_path;
    }

    void dfs(int u, int end, int curr_line, int times, vector<int>& path, vector<bool>& vst, vector<vector<pair<int, int>>>& g) {
        if (u == end) {
            path.push_back(u);
            if (times < min_times || times == min_times && cmp(path, min_path)) {
                min_times = times;
                min_path = path;
            }
            path.pop_back();
            return;
        }
        vst[u] = true;
        path.push_back(u);
        for (const auto& [v, line] : g[u]) {
            if (!vst[v]) {
                if (curr_line != line) {
                    ++times;
                }
                dfs(v, end, line, times, path, vst, g);
                if (curr_line != line) {
                    --times;
                }
            }
        }
        path.pop_back();
        vst[u] = false;
    }

    inline bool cmp(vector<int>&lv, vector<int>& rv) {
        int n = min((int)lv.size(), (int)rv.size());
        for (int i = 0; i < n; ++i) {
            if (lv[i] < rv[i])
                return true;
            else if (lv[i] > rv[i])
                return false;
        }
        return lv.size() < rv.size();
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> lines = {{4165,8075,3072,6302,3747,3616,1893},{7431,3616,3747,1893,8075,3219},{3072,6302,3747},{3616,3969},{7431,3616}};
    int start = 4165, end = 3219;
    Solution().metroRouteDesignI(lines, start, end);
    return 0;
}
// [[4165,8075,3072,6302,3747,3616,1893],[7431,3616,3747,1893,8075,3219],[3072,6302,3747],[3616,3969],[7431,3616]]
// 4165
// 3219