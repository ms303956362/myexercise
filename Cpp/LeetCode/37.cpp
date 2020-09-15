#include "usual.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(10, false)), col(9, vector<bool>(10, false)), block(9, vector<bool>(10, false));
        for (int i = 0; i != 9; ++i) {
            for (int j = 0; j != 9; ++j) {
                if (board[i][j] != '.') {
                    int d = board[i][j] - '0';
                    row[i][d] = true;
                    col[j][d] = true;
                    block[3 * (i / 3) + j / 3][d] = true;
                }
            }
        }
        backtrack(0, 0, board, row, col, block);
    }

    bool backtrack(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& block) {
        if (j == 9) {
            if (i == 8)
                return true;
            else
                return backtrack(i + 1, 0, board, row, col, block);
        }
        if (board[i][j] != '.') {
            return backtrack(i, j + 1, board, row, col, block);
        } else {
            for (int d = 1; d != 10; ++d) {
                if (!row[i][d] && !col[j][d] && !block[3 * (i / 3) + j / 3][d]) {
                    board[i][j] = d + '0';
                    row[i][d] = true;
                    col[j][d] = true;
                    block[3 * (i / 3)  + j / 3][d] = true;
                    if (backtrack(i, j + 1, board, row, col, block))
                        return true;
                    row[i][d] = false;
                    col[j][d] = false;
                    block[3 * (i / 3) + j / 3][d] = false;
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board{{ '5', '3', '.', '.', '7', '.', '.', '.', '.' }, { '6', '.', '.', '1', '9', '5', '.', '.', '.' }, { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, { '8', '.', '.', '.', '6', '.', '.', '.', '3' }, { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, { '7', '.', '.', '.', '2', '.', '.', '.', '6' }, { '.', '6', '.', '.', '.', '.', '2', '8', '.' }, { '.', '.', '.', '4', '1', '9', '.', '.', '5' }, { '.', '.', '.', '.', '8', '.', '.', '7', '9' }};
    Solution().solveSudoku(board);
    return 0;
}
