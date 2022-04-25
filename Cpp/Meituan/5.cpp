#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> p(n), color(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> color[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] > 0) {
            g[p[i] - 1].push_back(i);
        }
    }
    vector<int> ans(2);
    function<void(int)> dfs = [&](int u)
    {
        int cnt = 0, sz = g[u].size();
        for (const auto& v : g[u])
        {
            if (color[v] != color[u]) {
                ++cnt;
            }
            dfs(v);
        }
        if (color[u] == 0) {
            if (sz == 0 || cnt >= 1) {
                ++ans[0];
            }
        } else {
            if (sz == 0 || cnt == sz) {
                ++ans[1];
            }
        }
    };
    dfs(0);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
