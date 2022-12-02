#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> in(n), time(n);
    for (int i = 0; i < n; ++i) {
        cin >> time[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        ++in[v];
    }
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) {
            q.emplace(-time[i], i);
        }
    }
    vector<int> ans(n);
    int level = 1;
    while (!q.empty()) {
        int l = q.size();
        for (int i = 0; i < l; ++i) {
            auto [t, u] = q.top();
            q.pop();
            ans[u] = level;
            ++level;
            for (const auto& v : g[u]) {
                if (in[v] > 0) {
                    --in[v];
                    if (in[v] == 0) {
                        q.emplace(-time[v], v);
                    }
                }
            }
        }
        
    }
    for (const auto& u : ans) {
        cout << u << " ";
    }
    cout << endl;
    return 0;
}
