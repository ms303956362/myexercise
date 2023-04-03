// IO
#include <iostream>
#include <iomanip>      // std::setprecision
#include <sstream>
// ordered container
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <stack>
#include <queue>
// associative-container
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
// algorithm
#include <algorithm>
#include <cmath>
// utility
#include <initializer_list>
#include <iterator>
#include <memory>
#include <utility>
// c
#include <cstdio>
#include <cstdlib>
#include <cstring>
// functional
#include <functional>

using namespace std;

using ll = long long;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<string, int> d;
    int n;
    cin >> n;
    unordered_map<string, int> in;
    unordered_map<string, vector<string>> g;
    for (int i = 0; i < n; ++i) {
        string s, t;
        cin >> s >> t;
        g[s].push_back(t);
        ++in[t];
    }
    for (const auto& [_, d] : in) {
        if (d >= 2) {
            cout << "No" << '\n';
            return 0;
        }
    }
    unordered_map<string, int> vst;
    function<bool(const string&)> dfs = [&](const string& u) {
        vst[u] = 1;
        for (const auto& v : g[u]) {
            if (vst[v] == 1) {
                return false;
            } else if (vst[v] == 2) {
                continue;
            } else if (!dfs(v)) {
                return false;
            }
        }
        vst[u] = 2;
        return true;
    };
    for (const auto& [u, _] : g) {
        if (!vst.count(u) && !dfs(u)) {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';
    return 0;
}
