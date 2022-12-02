#include "usual.h"

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> cnt(n);
        set<int> free;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        for (int i = 0; i < n; ++i) {
            free.insert(i);
        }
        for (const auto& m : meetings) {
            long long st = m[0], end= m[1];
            int duration = m[1] - m[0];
            while (!q.empty() && q.top().first <= st) {
                auto [e, i] = q.top();
                q.pop();
                free.insert(i);
            }
            int i = 0;
            if (!free.empty()) {
                i = *free.begin();
                free.erase(free.begin());
            } else {
                auto [e, j] = q.top();
                q.pop();
                i = j;
                end += e - st;
            }
            ++cnt[i];
            q.emplace(end, i);
        }
        int max_cnt = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] > max_cnt) {
                max_cnt = cnt[i];
                ans = i;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n = 2;
    vector<vector<int>> m{{43,44},{34,36},{11,47},{1,8},{30,33},{45,48},{23,41},{29,30}};
    Solution().mostBooked(n, m);
    return 0;
}
