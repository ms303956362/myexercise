#include <iostream>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int j;
        cin >> j;
        g[i + 1].push_back(j - 1);
        g[j - 1].push_back(i + 1);
    }
    vector<int> assign(n), unassign(n);
    function<pair<int, int>(int, int)> dfs = [&](int u, int f) {
        int sum = 0, extra = 0xff3f3f3f;
        for (const auto& v : g[u]) {
            if (v == f) {
                continue;
            }
            auto p = dfs(v, u);
            unassign[v] = p.first;
            assign[v] = p.second;
            sum += max(p.first, p.second);
            extra = max(extra, unassign[v] + 1 - max(unassign[v], assign[v]));
        }
        return make_pair(sum, sum + extra);
    };
    auto p = dfs(0, -1);
    cout << max(p.first, p.second) << endl;
    return 0;
}
