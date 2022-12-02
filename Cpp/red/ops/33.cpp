#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int start[100005], finish[100005], cost[100005];

int main(int argc, char const *argv[])
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> start[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> finish[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> cost[i];
    }
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        g[start[i] - 1].emplace_back(finish[i] - 1, cost[i]);
        g[finish[i] - 1].emplace_back(start[i] - 1, cost[i]);
    }
    auto check = [&](long long x) -> bool {
        vector<bool> vst(n);
        queue<int> q;
        q.push(0);
        vst[0] = true;
        int step = 0;
        while (!q.empty()) {
            int len = q.size();
            if (step > k) {
                return false;
            }
            for (int i = 0; i < len; ++i) {
                auto u = q.front();
                q.pop();
                if (u == n - 1) {
                    return true;
                }
                for (const auto& p : g[u]) {
                    long long v = p.first, c = p.second;
                    if (c <= x && !vst[v]) {
                        vst[v] = true;
                        q.emplace(v);
                    }
                }
            }
            ++step;
        }
        return false;
    };
    long long l = 1, h = 2e15;
    while (l <= h) {
        long long x = (l + h) / 2;
        if (check(x)) {
            h = x - 1;
        } else {
            l = x + 1;
        }
    }
    cout << l << endl;
    return 0;
}
