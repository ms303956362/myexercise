#include <iostream>
#include <utility>
#include <functional>
using namespace std;

inline pair<int, int> dir(char c) {
    switch(c) {
    case '<':
        return make_pair(0, -1);
    case '>':
        return make_pair(0, 1);
    case '^':
        return make_pair(-1, 0);
    case 'v':
        return make_pair(1, 0);
    }
    return make_pair(0, 0);
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            mat[i][j] = s[j];
        }
    }
    vector<vector<int>> dis(n, vector<int>(m, -1));
    function<void(int, int)> go = [&](int x, int y) {
        unordered_map<int, int> idx;
        vector<pair<int, int>> path;
        path.emplace_back(x, y);
        int base = 0;
        while (0 <= x && x < n && 0 <= y && y < m && dis[x][y] == -1) {
            auto [dx, dy] = dir(mat[x][y]);
            x += dx;
            y += dy;
            if (!(0 <= x && x < n && 0 <= y && y < m)) {
                break;
            } else if (dis[x][y] != -1) {
                base = dis[x][y];
                break;
            } else if (idx.count(x * m + y)) {
                int cycle = path.size() - idx[x * m + y];
                while (idx.count(x * m + y)) {
                    x = path.back().first;
                    y = path.back().second;
                    dis[x][y] = cycle;
                    path.pop_back();
                    idx.erase(x * m + y);
                    ++base;
                }
                break;
            }
            idx[x * m + y] = path.size();
            path.emplace_back(x, y);
        }
        int len = base;
        while (!path.empty()) {
            auto [x, y] = path.back();
            path.pop_back();
            ++len;
            dis[x][y] = len;
        }
    };
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dis[i][j] == -1) {
                go(i, j);
            }
            ans = max(ans, dis[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
