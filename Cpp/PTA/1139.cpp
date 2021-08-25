#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> names;
    unordered_map<int, int> idx;
    vector<vector<bool>> g(n, vector<bool>(n, false));
    int j = 0;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (!idx.count(u)) {
            idx[u] = j++;
            names.push_back(u);
        }
        if (!idx.count(v)) {
            idx[v] = j++;
            names.push_back(v);
        }
        g[idx[u]][idx[v]] = true;
        g[idx[v]][idx[u]] = true;
    }
    int k;
    cin >> k;
    bool first = true;
    for (int i = 0; i < k; ++i) {
        if (first)
            first = false;
        else
            cout << endl;
        int u, v;
        cin >> u >> v;
        unordered_set<int> su, sv;
        set<pair<int, int>> st;
        for (const auto& u1 : g[u]) {
            if (names[u1] * names[u] > 0 && u1 != v)
                su.insert(u1);
        }
        for (const auto& v1 : g[v]) {
            if (names[v1] * names[v] > 0 && v1 != u)
                sv.insert(v1);
        }
        for (const auto& u1 : su) {
            for (const auto& v1 : sv) {
                if (g[u1][v1])
                    st.emplace(abs(names[u1]), abs(names[v1]));
            }
        }
        
        cout << st.size();
        for (const auto& [u1, v1] : st) {
            cout << endl;
            cout << u1 << " " << v1;
        }
    }
    return 0;
}
