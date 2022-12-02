#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

bool vst[105][105];

int main(int argc, char const *argv[])
{
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int x = 0, y = 0, sz = 1;
    vst[x][y] = true;
    map<char, pair<int, int>> dir{{'W', {-1, 0}}, {'A', {0, -1}}, {'S', {1, 0}}, {'D', {0, 1}}};
    int i = 0;
    for (; i < k; ++i) {
        auto [dx, dy] = dir[s[i]];
        int u = x + dx, v = y + dy;
        if (0 <= u && u < n && 0 <= v && v < m && !vst[u][v]) {
            ++sz;
            vst[u][v] = true;
        }
        if (sz == n * m) {
            break;
        }
        x = u;
        y = v;
    }
    if (sz == n * m) {
        cout << "Yes" << endl;
        cout << i + 1 << endl;
    } else {
        cout << "No" << endl;
        cout << n * m - sz << endl;
    }
    return 0;
}
