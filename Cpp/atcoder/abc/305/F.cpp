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
#include <numeric>
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
    int n, m;
    cin >> n >> m;
    int u = 0;
    vector<vector<int>> g(n);
    vector<bool> vst(n, false);
    vector<int> idx(n);
    stack<int> fa;
    while (u + 1 != n) {
        int k;
        cin >> k;
        for (int i = 0; i < k; ++i) {
            int v;
            cin >> v;
            --v;
            if (!vst[u]) {
                g[u].push_back(v);
            }
        }
        vst[u] = true;
        int nxt = -1;
        while (idx[u] < g[u].size()) {
            if (!vst[g[u][idx[u]]]) {
                fa.push(u);
                nxt = g[u][idx[u]];
                ++idx[u];
                break;
            } else {
                ++idx[u];
            }
        }
        if (nxt == -1) {
            nxt = fa.top();
            fa.pop();
        }
        u = nxt;
        cout << u + 1 << endl;
    }
    string s;
    cin >> s;
    return 0;
}
