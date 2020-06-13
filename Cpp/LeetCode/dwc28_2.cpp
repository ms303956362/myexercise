#include "usual.h"

class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : n(rectangle.size()), m(rectangle[0].size()) {
        rec.resize(n, vector<int>(m, 0));
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                rec[i][j] = rectangle[i][j];
            }
        }
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                rec[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return rec[row][col];
    }

private:
    int n;
    int m;
    vector<vector<int>> rec;
};