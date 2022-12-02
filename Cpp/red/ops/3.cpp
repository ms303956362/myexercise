#include <iostream>
#include <vector>

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
        g[start[i] - 1].emplace_back()
    }
    return 0;
}
