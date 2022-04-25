#include "usual.h"

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<unordered_map<int, vector<int>>> dp(n);
        for (int u = 0; u < n; ++u) {
            for (const auto& v : g[u]) {
                dp[u][v] = vector<int>(4);
                dp[u][v][0] = scores[u];
            }
        }
        for (int t = 1; t < 4; ++t) {
            for (int u = 0; u < n; ++u) {
                int max_score = -1, max_v = -1, second_max_score = -2, second_max_v = -2;
                for (const auto& v : g[u]) {
                    int score = dp[v][u][t - 1] + scores[u];
                    if (score > max_score) {
                        max_score = score;
                        max_v = v;
                    } else if (score > second_max_score) {
                        second_max_score = score;
                        second_max_v = v;
                    }
                }
                if (max_score == second_max_score) {
                    for (const auto& v : g[u]) {
                        dp[u][v][t] = max_score;
                    }
                } else {
                    for (const auto& v : g[u]) {
                        if (v == max_v) {
                            dp[u][v][t] = second_max_score;
                        } else {
                            dp[u][v][t] = max_score;
                        }
                    }
                }
            }
        }
        int ans = -1;
        for (int u = 0; u < n; ++u) {
            for (const auto& v : g[u]) {
                ans = max(ans, dp[u][v][3]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
