#include "usual.h"

class Solution {
    const int EMPTY = 0, GUARD = 1, WALL = 2;

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>> is_guarded(m, vector<bool>(n, false));
        vector<vector<int>> type(m, vector<int>(n, 0));
        for (const auto& p : guards) {
            type[p[0]][p[1]] = GUARD;
        }
        for (const auto& p : walls) {
            type[p[0]][p[1]] = WALL;
        }
        for (int i = 0; i < m; ++i) {
            bool has_guard = false;
            for (int j = 0; j < n; ++j) {
                if (type[i][j] == GUARD) {
                    has_guard = true;
                } else if (type[i][j] == WALL) {
                    has_guard = false;
                } else {
                    if (!is_guarded[i][j] && has_guard) {
                        is_guarded[i][j] = true;
                    }
                }
            }
            has_guard = false;
            for (int j = n - 1; j >= 0; --j) {
                if (type[i][j] == GUARD) {
                    has_guard = true;
                } else if (type[i][j] == WALL) {
                    has_guard = false;
                } else {
                    if (!is_guarded[i][j] && has_guard) {
                        is_guarded[i][j] = true;
                    }
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            bool has_guard = false;
            for (int i = 0; i < m; ++i) {
                if (type[i][j] == GUARD) {
                    has_guard = true;
                } else if (type[i][j] == WALL) {
                    has_guard = false;
                } else {
                    if (!is_guarded[i][j] && has_guard) {
                        is_guarded[i][j] = true;
                    }
                }
            }
            has_guard = false;
            for (int i = m - 1; i >= 0; --i) {
                if (type[i][j] == GUARD) {
                    has_guard = true;
                } else if (type[i][j] == WALL) {
                    has_guard = false;
                } else {
                    if (!is_guarded[i][j] && has_guard) {
                        is_guarded[i][j] = true;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (type[i][j] == EMPTY && !is_guarded[i][j]) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
