#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int a[1005][1005];

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    auto isvalid = [&](int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m && a[i][j] == 1;
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int cnt = 4;
            cnt -= isvalid(i + 1, j);
            cnt -= isvalid(i - 1, j);
            cnt -= isvalid(i, j + 1);
            cnt -= isvalid(i, j - 1);
            ans += cnt;
        }
    }
    cout << ans << endl;
    return 0;
}
