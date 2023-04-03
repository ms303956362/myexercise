#include "usual.h"

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<pair<int, int>> ql_wait, qr_wait;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ql_work, qr_work;
        for (int i = 0; i < k; ++i) {
            ql_wait.emplace(time[i][0] + time[i][2], i);
        }
        int ans = 0, t = 0, m = n;
        while (n > 0) {
            bool ok1 = false, ok2 = false;
            while (!ql_work.empty() && ql_work.top().first <= t) {
                auto [_, i] = ql_work.top();
                ql_work.pop();
                ql_wait.emplace(time[i][0] + time[i][2], i);
            }
            while (!qr_work.empty() && qr_work.top().first <= t) {
                auto [_, i] = qr_work.top();
                qr_work.pop();
                qr_wait.emplace(time[i][0] + time[i][2], i);
            }
            if (!qr_wait.empty()) {
                auto [_, i] = qr_wait.top();
                qr_wait.pop();
                t += time[i][2];
                ok2 = true;
                ql_work.emplace(t + time[i][3], i);
                --n;
                ans = t;
            } else if (!ql_wait.empty() && m > 0) {
                auto [_, i] = ql_wait.top();
                ql_wait.pop();
                t += time[i][0];
                ok1 = true;
                qr_work.emplace(t + time[i][1], i);
                --m;
            }
            if (!ok1 && !ok2) {
                if (!ql_work.empty() && !qr_work.empty()) {
                    if (ql_work.top().first < qr_work.top().first) {
                        t = max(t, ql_work.top().first);
                    } else {
                        t = qr_work.top().first;
                    }
                } else if (!ql_work.empty()) {
                    t = ql_work.top().first;
                } else {
                    t = qr_work.top().first;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n = 3, k = 2;
    vector<vector<int>> time{{1,9,1,8},{10,10,10,10}};
    Solution().findCrossingTime(n, k, time);
    return 0;
}
