#include "usual.h"

class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long> cnt(5);
        unordered_map<int, unordered_set<int>> st;
        for (const auto& pos : coordinates) {
            st[pos[0]].insert(pos[1]);
        }
        auto is_valid = [&](int x, int y) {
            return 0 <= x && x < m && 0 <= y && y < n;
        };
        vector<vector<pair<int, int>>> offsets{
            {{-1, -1}, {-1, 0}, {0, -1}, {0, 0}},
            {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
            {{0, -1}, {0, 0}, {1, -1}, {1, 0}},
            {{-1, 0}, {-1, 1}, {0, 0}, {0, 1}}
        };
        auto check = [&](int x, int y, const vector<pair<int, int>>& offset) {
            int cnt = 0;
            for (const auto& [dx, dy] : offset) {
                if (!is_valid(x + dx, y + dy)) {
                    return -1;
                }
                if (st.count(x + dx) && st[x + dx].count(y + dy)) {
                    ++cnt;
                }
            }
            return cnt;
        };
        for (const auto& pos : coordinates) {
            int x = pos[0], y = pos[1];
            for (const auto& offset : offsets) {
                int c = check(x, y, offset);
                if (c != -1) {
                    ++cnt[c];
                }
            }
        }
        cnt[0] = ((long long)m - 1) * ((long long)n - 1);
        for (int i = 1; i <= 4; ++i) {
            cnt[i] /= i;
            cnt[0] -= cnt[i];
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
