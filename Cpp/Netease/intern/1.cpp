#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0x3f3f3f3f));
    dp[0][0] = 0;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            if (i == 0 && j == 0)
                continue;
            int i1 = max(i - x, 0), j1 = j;
            int i2 = max(i - y, 0), j2 = max(j - y, 0);
            int i3 = i, j3 = max(j - x, 0);
            dp[i][j] = min({dp[i1][j1], dp[i2][j2], dp[i3][j3]}) + 1;
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}
