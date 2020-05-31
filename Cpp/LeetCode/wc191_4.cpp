#include "usual.h"

int combinat(int m, int n) {
    vector<vector<int>> mat(m, vector<int>(n, 0));
    int i, j;   
    if(n == 0 || m == n)
        return 1;
    for(j = 0; j <= n; j++) {
        mat[j][j] = 1;
        for(i = j+1; i <= m; i++) {
            if(j == 0)
                mat[i][j] = 1;
            else
                mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
        }
    }
    return mat[m][n];
}

int main(int argc, char const *argv[])
{
    
    return 0;
}