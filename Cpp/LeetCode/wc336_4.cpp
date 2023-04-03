#include "usual.h"

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n = tasks.size(), m = 0;
        for (int i = 0; i < n; ++i) {
            m = max(m, tasks[i][1]);
        }
        vector<unordered_set<int>> t_tasks(m + 1);
        for (int i = 0; i < n; ++i) {
            for (int t = tasks[i][0]; t <= tasks[i][1]; ++t) {
                t_tasks[t].insert(i);
            }
        }
        int ans = 0;
        vector<bool> vst(m + 1);
        while (true) {
            int t = -1, max_cnt = 0;
            for (int i = 1; i <= m; ++i) {
                if (vst[i]) {
                    continue;
                }
                if (t_tasks[i].size() > max_cnt) {
                    max_cnt = t_tasks[i].size();
                    t = i;
                }
            }
            if (t == -1) {
                break;
            }
            vst[t] = true;
            vector<int> vt;
            for (const auto& i : t_tasks[t]) {
                --tasks[i][2];
                if (tasks[i][2] == 0) {
                    for (int j = tasks[i][0]; j <= tasks[i][1]; ++j) {
                        if (j != t) {
                            t_tasks[j].erase(i);
                        }
                    }
                    vt.push_back(i);
                }
            }
            for (const auto& i : vt) {
                t_tasks[t].erase(i);
            }
            ++ans;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
