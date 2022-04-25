#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> out(n * k, vector<int>(n * k));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = i * k, y = j * k;
            for (int u = x; u < x + k; ++u) {
                for (int v = y; v < y + k; ++v) {
                    out[u][v] = a[i][j];
                }
            }
        }
    }
    for (int i = 0; i < n * k; ++i) {
        for (int j = 0; j < n * k; ++j) {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
