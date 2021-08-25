#include "usual.h"

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        char opp_color = (color == 'B' ? 'w' : 'B');
        // up
        int cnt = 0, i = rMove - 1;
        while (i >= 0 && board[i][cMove] == opp_color) {
            ++cnt;
            --i;
        }
        if (i >= 0 && cnt >= 1 && board[i][cMove] == color)
            return true;
        // down
        cnt = 0, i = rMove + 1;
        while (i < 8 && board[i][cMove] == opp_color) {
            ++cnt;
            ++i;
        }
        if (i < 8 && cnt >= 1 && board[i][cMove] == color)
            return true;
        // left
        cnt = 0, i = cMove - 1;
        while (i >= 0 && board[rMove][i] == opp_color) {
            ++cnt;
            --i;
        }
        if (i >= 0 && cnt >= 1 && board[rMove][i] == color)
            return true;
        // right
        cnt = 0, i = cMove + 1;
        while (i < 8 && board[rMove][i] == opp_color) {
            ++cnt;
            ++i;
        }
        if (i < 8 && cnt >= 1 && board[rMove][i] == color)
            return true;
        // upleft
        int cnt = 0, i = rMove - 1, j = cMove - 1;
        while (i >= 0 && j >= 0 && board[i][j] == opp_color) {
            ++cnt;
            --i;
            --j;
        }
        if (i >= 0 && j >= 0&& cnt >= 1 && board[i][j] == color)
            return true;
        // upright
        int cnt = 0, i = rMove - 1, j = cMove + 1;
        while (i >= 0 && j < 8 && board[i][j] == opp_color) {
            ++cnt;
            --i;
            ++j;
        }
        if (i >= 0 && j < 8 && cnt >= 1 && board[i][j] == color)
            return true;
        // downleft
        int cnt = 0, i = rMove + 1, j = cMove - 1;
        while (i < 8 && j >= 0 && board[i][j] == opp_color) {
            ++cnt;
            ++i;
            --j;
        }
        if (i < 8 && j >= 0 && cnt >= 1 && board[i][j] == color)
            return true;
        // downright
        int cnt = 0, i = rMove + 1, j = cMove + 1;
        while (i < 8 && j < 8 && board[i][j] == opp_color) {
            ++cnt;
            ++i;
            ++j;
        }
        if (i < 8 && j < 8 && cnt >= 1 && board[i][j] == color)
            return true;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
