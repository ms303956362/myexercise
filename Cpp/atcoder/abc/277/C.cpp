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
    int n;
    cin >> n;
    unordered_map<int, unordered_set<int>> g;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    unordered_set<int> vst;
    queue<int> q;
    q.push(1);
    vst.insert(1);
    int ans = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans = max(ans, u);
        for (const auto& v : g[u]) {
            if (!vst.count(v)) {
                vst.insert(v);
                q.push(v);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
