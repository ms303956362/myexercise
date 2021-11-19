#include "usual.h"

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size(), l = word.size();
        string word2(word);
        reverse(word2.begin(), word2.end());
        vector<vector<bool>> vst1(n, vector<bool>(m, false)), vst2(n, vector<bool>(m, false)), vst3(n, vector<bool>(m, false)), vst4(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == '#')
                    continue;
                // hori
                if (!vst1[i][j] && (j == 0 || (board[i][j - 1] == '#')) && m - j >= l) {
                    bool ok = true;
                    int k = 0;
                    for (k = 0; k < l; ++k) {
                        // vst1[i][j + k] = true;
                        if (board[i][j + k] != ' ' && board[i][j + k] != word[k]) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok && (j + k == m || board[i][j + k] == '#'))
                        return true;
                    // else {
                    //     while (k < l && board[i][j + k] != '#') {
                    //         vst1[i][j + k] = true;
                    //         ++k;
                    //     }
                    // }
                }
                if (!vst3[i][j] && (j == 0 || (board[i][j - 1] == '#')) && m - j >= l) {
                    bool ok = true;
                    int k = 0;
                    for (k = 0; k < l; ++k) {
                        // vst3[i][j + k] = true;
                        if (board[i][j + k] != ' ' && board[i][j + k] != word2[k]) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok && (j + k == m || board[i][j + k] == '#'))
                        return true;
                    // else {
                    //     while (k < l && board[i][j + k] != '#') {
                    //         vst3[i][j + k] = true;
                    //         ++k;
                    //     }
                    // }
                }
                // vert
                if (!vst2[i][j] && (i == 0 || board[i - 1][j] == '#') && n - i >= l) {
                    bool ok = true;
                    int k = 0;
                    for (k = 0; k < l; ++k) {
                        // vst2[i + k][k] = true;
                        if (board[i + k][j] != ' ' && board[i + k][j] != word[k]) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok && (i + k == n || board[i + k][j] == '#'))
                        return true;
                    // else {
                    //     while (k < l && board[i + k][j] != '#') {
                    //         vst2[i + k][j] = true;
                    //         ++k;
                    //     }
                    // }
                }
                if (!vst4[i][j] && (i == 0 || board[i - 1][j] == '#') && n - i >= l) {
                    bool ok = true;
                    int k = 0;
                    for (k = 0; k < l; ++k) {
                        // vst4[i + k][k] = true;
                        if (board[i + k][j] != ' ' && board[i + k][j] != word2[k]) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok && (i + k == n || board[i + k][j] == '#'))
                        return true;
                    // else {
                    //     while (k < l && board[i + k][j] != '#') {
                    //         vst1[i + k][j] = true;
                    //         ++k;
                    //     }
                    // }
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> v{{'x', '#', ' '}, {'g', 'v', 'o'}, {'b', 'n', '#'}, {'e', 'w', 'n'}, {'y', 'f', 'p'}, {' ', 'e', 'v'}, {'t', 't', 'u'}, {'#', 'i', ' '}, {'#', ' ', 'x'}, {'f', ' ', ' '}, {' ', 'm', 'd'}, {' ', 't', '#'}, {'w', 'z', '#'}, {'c', 'u', 'h'}};
    string w("vnwfetietmtzu");
    Solution().placeWordInCrossword(v, w);
    return 0;
}
