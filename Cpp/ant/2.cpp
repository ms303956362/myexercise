#include <iostream>
#include <vector>
#include <functional>

using namespace std;

using ll = unsigned long long;

ll dfs(vector<vector<ll>>& g, ll u, ll f, ll c) {
    ll cnt = u - c;
    for (const auto& v : g[u]) {
        if (v == f) {
            continue;
        }
        cnt += dfs(g, v, u, u);
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<ll>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << dfs(g, 0, -1, 0) << endl;
    return 0;
}
