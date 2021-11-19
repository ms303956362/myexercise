#include "usual.h"

class Solution {
    int ans;

public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        vector<vector<pair<int, int>>> d{
            {{-1, 0}, {1, 0}, {0, -1}, {0, 1}},
            {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}},
            {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}};
        vector<int> idx;
        for (const auto &s : pieces) {
            if (s == "rook")
                idx.push_back(0);
            else if (s == "queen")
                idx.push_back(1);
            else
                idx.push_back(2);
        }
        unordered_set<int> s;
        ans = 0;
        int n = pieces.size();
        for (const auto& p : positions) {
            s.insert(p[0] * 10 + p[1]);
        }
        dfs(0, n, positions, idx, d, s);
        return ans;
    }

    void dfs(int i, int n, vector<vector<int>>& positions, vector<int>& idx, vector<vector<pair<int, int>>>& d, unordered_set<int>& s) {
        if (i == n) {
            ++ans;
            return;
        }
        int r = positions[i][0], c = positions[i][1];
        dfs(i + 1, n, positions, idx, d, s);
        s.erase(r * 10 + c);
        for (const auto& [dx, dy] : d[idx[i]]) {
            int x = r + dx, y = c + dy;
            while (0 < x && x <= 8 && 0 < y && y <= 8 && !s.count(x * 10 + y)) {
                s.insert(x * 10 + y);
                dfs(i + 1, n, positions, idx, d, s);
                s.erase(x * 10 + y);
                x += dx;
                y += dy;
            }
        }
        s.insert(r * 10 + c);
    }
};

int main(int argc, char const *argv[])
{
    vector<string> s{"rook"};
    vector<vector<int>> positions{{1, 1}};
    Solution().countCombinations(s, positions);
    
    return 0;
}
