#include "usual.h"

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& l, const vector<int>& r) {
            return l[1] < r[1];
        });
        vector<pair<int, int>> q;
        for (int i = 0; i < queries.size(); ++i) {
            q.emplace_back(queries[i], i);
        }
        sort(q.begin(), q.end());
        int i = 0, j = 0, m = logs.size(), num = n;
        vector<int> cnt(n + 1), ans(queries.size());
        for (const auto& [t, k] : q) {
            while (j < m && logs[j][1] <= t) {
                if (cnt[logs[j][0]] == 0) {
                    --num;
                }
                ++cnt[logs[j][0]];
                ++j;
            }
            while (i < m && logs[i][1] < t - x) {
                --cnt[logs[i][0]];
                if (cnt[logs[i][0]] == 0) {
                    ++num;
                }
                ++i;
            }
            ans[k] = num;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
