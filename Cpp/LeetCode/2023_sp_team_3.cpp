#include "usual.h"

int dp[101][101][101];

class Solution {
public:
    int extractMantra(vector<string>& matrix, string mantra) {
        auto check = [&]() {
            vector<bool> has(256);
            for (const auto& row : matrix) {
                for (const auto& c : row) {
                    has[c] = true;
                }
            }
            for (const auto& c : mantra) {
                if (!has[c]) {
                    return false;
                }
            }
            return true;
        };
        if (!check()) {
            return -1;
        }
        int m = matrix.size(), n = matrix[0].size(), l = mantra.size();
        vector<vector<pair<int, int>>> pos(256);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[matrix[i][j]].emplace_back(i, j);
            }
        }
        memset(dp, -1, sizeof(int)*m*n*l);
        // vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(l, -1)));
        function<void(int, int, int)> dfs = [&](int x, int y, int i) {
            if (dp[x][y][i] != -1) {
                return;
            }
            if (i == l - 1) {
                dp[x][y][i] = 1;
                return;
            }
            dp[x][y][i] = 0x3f3f3f3f;
            for (const auto& [u, v] : pos[mantra[i + 1]]) {
                dfs(u, v, i + 1);
                dp[x][y][i] = min(dp[x][y][i], abs(x - u) + abs(y - v) + 1 + dp[u][v][i + 1]);
            }
        };
        int ans = 0x3f3f3f3f;
        for (const auto& [x, y] : pos[mantra[0]]) {
            dfs(x, y, 0);
            ans = min(ans, x + y + dp[x][y][0]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}

/*
["aaabaaabbbabaabaababaababbaabbbabbabbabaaabbbbaaabaababababaaaababbbbbaaaaabaabaa","aaaaabbaaabbbabbaabbaaabbbabbabbbbaaabbbbaabbbabbbabbbaabbbbabaabbbbabababaabaaab","abaaababaaaaaaababbbbbbaaaabbbbbabbbabaaaaaabbbbaababbaaaabbbbbabababbbbaaaaabaab","babbababaabaabbbabbababababbabaabaabbabbbababbabbbbbbbaababaabbabbabababbaabaabbb","babbabbbaabaababbabaaaaaababababbabaabababbbbaaabbbbabbbbbbabbabbbbbaaabaabaaaabb","baabbababbbbaaaaabaaaabbbaabbbaabbabbabaaaabbaaaaaabbbaaababbaaaababbbaaabbbababa","aabbbabaaaabbbaabbbbaaaaaaabbababbabaaabbaaabbaababaabbbababbbbabaaababbbaaaaaaba","bbbbbabbbbabaaabbbbbbbbababbabbabababaaaaaabaabbaababbaaaabaabbbaaaabbbbbabaaabab","bbaaabaabaaabababaababbaaababbbbaaabbbaababababaaaabbbabbbbbaaabbaabbaaabbbbbaaaa","aabaabbaabbabbbbbbabbbbbbaabbbabbaaabbbaaabaaaaabaabaaabaabaabbababbbbbabbaabaaab","baaabaabaababbabbbbbaabbaaababaaababaababaaaaaabbbbaaabbbabbbabaaaaaaaaaaaaaaaaaa","bbaabaabaaaabaabaabaaaaaababababababbbaaabaabbbbaababbabbabbbababaabbbaabaababbba","ababaaababaabababbaabaabaaabaabaabbaababbabbbbababaaabbaabbbbbabbbaabbaaaabaaabbb","bbaabbababaabaabaaabaababaabbbaabbbbaaaaabbaaaaaabaabbabbaaaababbbaaababaababaaaa","abbababaaaaaaaababaabaabbbbaabaaabbaabaaabaabbaaaaaabaabbabbaabbbaaaaababbabbaabb","bbabbabaabbbaaaabaababababbaaabaaaabbabbabbabbaabbaaaaaabbbbbabbaaaaaaabbbaabbbba","bbbaabbabbbaabbaaaaaaabbbabbbbaabbbaabbabaabaabbabbbababbbabbbabbbbabbababaaaabaa","aabbaabbbaaaabababaababbaabbaaabbbbaabaababbaaabbbbababbbaababaaabbbabbaabaaabaaa","aabbaabaabaaaaabaabbbbaaabbabbbbaabbbabbaabbabaaabaaabbbbaaabbbbbabaaabababbaabab","babbaababbabbbbbbabbbabaaabbaaabaabababbaaaabbbabaaaabaabaabbababaabbabaaabaabaaa","bababaaaaababaabbaaaabbaaaabaabbbbabbababbaaababbbaababbbbbbbabaabbbabbbaabababba","aaababaababaabbbabbaaabbbabbbbabbbbbbaaaaababbaaabaaababbbaababababaabbaabbbbaaba","bababbaabababbbaaabaaaabbbabbbbbabaaababaaabbbababbaabaaababbaabbbbbbabababbabbba","abbabbbaabbabbbbbbabababaaaabaaababbaabbbbaaabbbabbbabbaaaaababbbaaabbabbbabbaaaa","babaaaaaaaaaaabaaabaaaabababababaaaaabbbbbbabbaababbbaabbaabbbababaaababbabbbbaab","bbabbbabbbaabaaabbbabbaababbbbababbbaabbababbabaaabbbabbabbbbbaabbabbaaaabbaabaaa","babaaabaaaababababbaabaabbbaabaaabbbbabaaabbababbaaaaabaabbbbbbbbabbbababbaababab","babbbbbaabbbbbbabbababbabbbbaabbabaababababbabbbbaaaaaabaabbababbbabbbbbaabaabbaa","bbabbbbabaaaaababbabaabbabbbaabbababbabaabababababbaababbabaaabbaaabaababbbbabbab","bbabababbabaaaabbabaabbbabbbaabbbaabbbaabbbbbbabaaabbbaabaabaaaaabababababaaaaaaa","abbbabababbabababbaaabbbbbaabbaaabbbbbaabbaaaaabbbbababbababaabaaaabbaababaaaaaaa","baabbaaabbbbaaabaabaabbaabbbbaaaaaababbbbabbaabaabbbaabbabbaaababbbbbbaabbbabbaba","baaabbbbbababaabababaaabbbbaaabaababbbbbbbbbabbbbbaaababaaaabbbbaabbaabaababbbbbb","bbaababbbabbbbaababaabbbaaabababbabaaaabbaabbbbbbaaabbbabbbbabbaabababbbbabbbbbba","bababaaaabaaaaabbbbbabababbbaabababaaaabbbbabbbbbbabaaabbaaaabbabbabaaaaababaaaab","bbbaaababbabbbbbabaaabbaaaabbbbbbbabaaaaabaaaabbbbbbaabbbaababbbaababaabaaaababaa","abbabaabbbabbbaaabbbbbbababbabaabbaabababababaabbaabbabaaaaaabaaaabbaaaababaabbba","aababaaabbbbbbbbbbbaaabaabaaabbbaaaabaaabaabaabbbaabbbaababaababababaabbababaabaa","abbabbaaaabbaabbbababbbbbbaaabbbaaaaaaaababbaabbaabbababbbaabbbbbbbabaabbbaaababb","aababaaaababbaaaaaaababaabbabbaaaaababaabbabbaaaaabbbaabbaabbaabbbbbbaaaabbbbabab","bbbaaababaaabbbaaabbbbabaaabbabbaabbbbbaabababbbaababbbbaaaabbbabbbbbaaabbababbba","babbbaabbbaabbbbbaaababbbaababbbababaabaaababbaaaababaaabbbaaaaaabbabaaabaabaaaab","abbbbababaababbbbbbbbababababbaaaaabbaabbababaabaaabaaaabbbabbbaabbaaababaabaaaba","aabbbaaaaababbbaaaaaabaaababbbabaabbabbaababbbabaaaaaaaaabbabbbabaabbbabbbbbbabbb","baaaabababbaabbbaabbbababaaabababbbaabaabbaabbaabbbbababbababbbaaaaababbbbbaaabaa","babbaabababaaabbbaaaaaabbbabbabbbbaaaabbaaaaabbbbababaaabbbabbaababababbaaaababaa","bbaaaabbabbbaabbbaaabaaabaababbbbbbabbbbaaaabbbbbabaaaaabbabbababbbabbabbaabbaaab","aabbbaabbabbabababbbabbbbbabbaabbbbababbbabaaaaababababaaaabbbbaabaaaababbababbbb","bbabbbabbaaabaaaabababbaabaabaaaabbbbaaaaabbaabaabbbbaaaaaabbbbbaaaabbbaabaabbabb","bbbaaaabbbbbbabbbbbbaaabaaaaabbabaababbabbbbabaabbabaabaaababbbabababbbaaaababaaa","bbaabbaababbaaabbbbaabbbaabaababbabbbaaababbbababaaaabbaababaababbbababbababaaaab","abaaaaaaababaaabbbaaababaabbbbbbbabbbbbaababbbbabbbbaabaaaaabaaaabbaaababbbabbaba","baaaaababbbbbbabbbbaaababaaabbababaaabbbbbbbbabbbabbbbaaaaaaaabbbbbaabbabaaaabbbb","abaaaabbbbabababbaabaababbabbababbbabababbabbbabbbbbaaaaaababbabbabaabbababaababb","aabbabbabbbabaabbbaabbbaaaabbabaababbbaaabaababbaababbaaabaabaaabbbaaabbbaabbabba","bbaabbaababbababababaabbabbbbbbabaaababbaababaabbaaabababbbbabaaaaabaabbabbaaaabb","bbbababbaaaaabbaabbbaaaaaaaabaaababaaaaaaabaaabaabaabbaabaabbbbbabbbababbabbaabbb","abaaaabaaabaabababbababbbbbaabbbaaabbbababbbaabaabbababbaaabbbbaaaaabbababbbababb","aaababababaababbbaaaaaaababbabaaaaabbabbabababababaabbbbabbbbaaababaabaababbababb","abbabbbabababaabaabbbbaaaaababaababbabbbbabbbbbababaababbaaaabaabbababaaaabbaaabb","aaaaababbaaaaabaaabbabaaabbbabbaaaabaabbabbababbbaaaabbaaababbbabbabbabaabbbaaaba","aaaaaaabbbaabbbabbbabbbaaabbabbbabaabbbaaabababbbaaaabaababbabbaabbbbaaabbbbbbbba","abaaabaabbbaabbbaabbaababbaabbaaabaababbbaababbabaabaabbabaabbbbbbabbaaaabbbbbbab","aaababaabababbaabbbaababbaabaabbaabababbabbbaabbababaaabaaababbaabbaaaababababaab","abbbbbaaababababbaabababbbbbbaabaabbbabbbbaaaaaaaaaababbbabaaaaababbaaababbbbbaba","babbbbabaabaabbaabababbbababbabbbabaabababbbbaabaabbbababbbbabbbbbabbbbabbbbaaaba","ababbabbbabaaabaabababbbaabaabababbbbbaabbbaaabbaabaaaabbbababbbbabbbbbabaaabbbab","babaaaababbaabbabbaaabbbaababbbabbbbaababbbabaabaaabbaabaabababbbababaababbbaaaab","bbbbabbaaababaaababbabaababbabaaaaaabaabbbabbaaabbbbbbabbbaabbababaaababaabababaa","babbaabbbbbaababbabbbabbbaaaabaababaaaaabababaabbbbaaaaaaaaabbbaaabaabbbabbababba","aaaabbaabaaabbbaabbbabaaabaaaabaababbaabbabaaabbabbaabbababbababbbbbbaaabaabababb","abbbababbaaabbaaabaaabaabbbbbbaabbbaabbabbbabbbbaaaabbbabbbbaaabbabbbaaabababaabb","bbbbbbaaaaababbabbababbbaabbbbbbaaabaaaababaababbbaaaabbabbbabbbbbbbbbbaaaaababab","baaabbbabaabaababbabaabababbaabaaabaaaaaaaabbbaabbaabbbaaaabbaaaaaabababbbaabaaab","bbabbbaaaaaaaabbaabababaaaabbbbbbbaaabbbaabbaabbabbbaaabbbbababbaabbbaaaaaaaabbba","ababbaaaaaaaaaaabaabbaabaaababaaaaababbbabbbbaaaaababbabbbaabaabbbbbaababaabbbbaa","bbaabababaaabbababbbaaabaaabbbaaaaababbbbababaaabaaaabbabbbaabbbbbabaaabaabaaabaa","ababbabbbabbabaabaabbabababbabbbabbabaaaaaababbabbbaababbabaaabaaaabaabbbababbbaa","bbbbbabbabaaaabbaaabbbabababbaaabbababaaaabaaabaabbababaaabbbbabbbabbbbabbbbaabaa","bbbbbbabaabbbaaaaabaaaaababbabbabababaaaabaaabbbbbbaababbaabbbbabaabbbbbaaabbbabb","bbbaaaabbbbabbaaaaaaabbbbabaaabbabaaaaabbbaabbbbaaabaabbbbbbababbabbbaaabbaabaabb","abaaababaaaabbbbabbabababaabbbaabbbabaabbbaabbbaabaabaaaabbabaaabaabaababababaaba","bbbabbbbabaababaaabaabbbaaababaaabaababaaaaaabbbaaabaaaababbbababaabbbbabbabbabaa","aabaababbaaabaaabaaaabbabbbbbbbbbbbbabaabaaaaaaabbababaabbbabbaaaaabaaabbaaabbabb","baabbbaaababaaaaabababababbaaabaaaaabbbabaababaaabbabbabbaaaaaabaabbabbbbabbbaaab","bbabbbaaabbbbaaabaabbaabbabaabbbbbaaabbabbabbaabbbaaaaaabbaabababbbbbaaabbbbaabaa","ababbbbbabbaaaaabbaabbbaabababaabbaaabaabaabaabbaaabbababbbabbbbbbbbaaaababaabaab","aaababaababbbaaaabbabbbabbaaabaaabaaabaaaababaabaaaaaaaaabaabaabaaabbababaaaaabba","abbbabbabbabbabaabababbababaabaabbbabbaabbbbabaaabaaaaaabbaabbbbaabaababbabbbaaaa","aabbaaaaaabaababbabaaaaaaaaabbababbbabaaaaabaabaabaababaabaaabaabababbabaaaaabbaa","bbbbabbbabbaaabbaaaabbabababaabaabbaaababbaabaabbbabababaaabaababbabbaaabaaaaaaaa","abbbaabbaaaabaaaabaaaaaaaaababaaaabbabbbaabaabababbaabaaaaaaababbaabbabbbaaabbabb","bbbbaabbbaaaaaabaaabaababababbabbaabababaabbbbbbabaabbbbabaabaababbbaaababbbabbaa","abbabbbabbaabbaabbbbaaabbaaabbaabbbbbbbbaabbaabbbaaabbaabbbabbabaaababababababaab","bababbabbbaaaaaaaaabaaababababababbbbaaaaaaabaabaaabbbaaaaabbbaabbababaaabaabbaab","bbbbaabbbbbabbaabaaaabbbaabbabaaaabababbababbbbabbbbbbabaabbaabaaaabbabbaabbbaaba","ababaaabbabababbabbbbbabbaabaaababbbbaaabbabbbbabbaababbbbbaaaabbabbbbaaaabaabbba","aaaaababaabbabbaababbbaaababaabaaabbbbbaabaaababaabababbbbbbaabbaaabbaabababaabaa"]
"aababbbabaabbabaabaaaabaabbbaabbbaababaabbaabaabbbabababbbbbaaabbaabbbbaaabbaaabba"

*/