#include "usual.h"

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        unordered_map<char, pair<int, int>> dir{{{'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}, {'D', {1, 0}}}};
        int m = s.size();
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            queue<pair<int, int>> q;
            q.emplace(startPos[0], startPos[1]);
            int step = 0, j = i;
            while (!q.empty() && j < m) {
                auto [x, y] = q.front();
                q.pop();
                auto [dx, dy] = dir[s[j]];
                int a = x + dx, b = y + dy;
                if (0 <= a && a < n && 0 <= b && b < n) {
                    ++step;
                    ++j;
                    q.emplace(a, b);
                }
            }
            ans.push_back(step);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
