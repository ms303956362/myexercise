#include "usual.h"

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<vector<int>> q;
        int n = tasks.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        int time = 0;
        for (int i = 0; i < n; ) {
            if (q.empty()){
                q.push({-tasks[i][1], tasks[i][2], tasks[i][0]});
                ++i;
            }
            ans.push_back(q.top()[2]);
            time += -q.top()[0];
            q.pop();
            while ((i < n && tasks[i][0] <= time)){
                q.push({-tasks[i][1], tasks[i][2], tasks[i][0]});
                ++i;
            }
        }
        while (!q.empty()) {
            ans.push_back(q.top()[2]);
            q.pop();
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v1{{1, 2}, { 2, 4 }, { 3, 2 }, { 4, 1 }};
    Solution().getOrder(v1);
    return 0;
}
