#include <iostream>
#include <vector>

using namespace std;



int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n, -1)), b(m, vector<int>(n, -1));;
    if ((m + n) % 2 == 0) {
        int val = 1;
        for (int s = 0; s < (m + n) / 2; ++s) {
            int x, y, dx, dy;
            if (s % 2 == 0) {
                x = s;
                y = 0;
                dx = -1;
                dy = 1;
            } else {
                x = 0;
                y = s;
                dx = 1;
                dy = -1;
            }
            if (s == (m + n) / 2 - 1) {
                if (m % 2 == 1) {
                    while (x != m / 2 && y != n / 2) {
                        a[x][y] = val;
                        val += 2;
                        x += dx;
                        y += dy;
                    }
                    a[m / 2][n / 2] = 0;
                } else {

                }
            } else {
                while (0 <= x && x < m && 0 <= y && y < n) {
                    a[x][y] = val;
                    val += 2;
                    x += dx;
                    y += dy;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == -1) {
                    a[i][j] = a[m - 1 - i][n - 1 - j] + 1;
                }
            }
        }
    } else {
        int val = 1;
        for (int s = 0; s < m + n - 1; ++s) {
            int x, y, dx, dy;
            if (s % 2 == 0) {
                x = s;
                y = 0;
                dx = -1;
                dy = 1;
            } else {
                x = 0;
                y = s;
                dx = 1;
                dy = -1;
            }
            if (s < (m + 2) / 2) {
                while (0 <= x && x < m && 0 <= y && y < n) {
                    a[x][y] = -val;
                    val += 2;
                    x += dx;
                    y += dy;
                }
            } else {
                while (0 <= x && x < m && 0 <= y && y < n) {
                    a[x][y] = val;
                    val += 2;
                    x += dx;
                    y += dy;
                }
            }
        }
        val = 2;
        for (int s = 0; s < m + n - 1; ++s) {
            int x, y, dx, dy;
            if (s % 2 == 0) {
                x = s;
                y = 0;
                dx = -1;
                dy = 1;
            } else {
                x = 0;
                y = s;
                dx = 1;
                dy = -1;
            }
            if (s < (m + 2) / 2) {
                while (0 <= x && x < m && 0 <= y && y < n) {
                    a[x][y] = -val;
                    val += 2;
                    x += dx;
                    y += dy;
                }
            } else {
                while (0 <= x && x < m && 0 <= y && y < n) {
                    a[x][y] = val;
                    val += 2;
                    x += dx;
                    y += dy;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == -1) {
                    a[i][j] = a[m - 1 - i][n - 1 - j] + 1;
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
