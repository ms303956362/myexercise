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
    vector<string> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<string> d(m);
    vector<int> p(m + 1);
    for (int i = 0; i < m; ++i) {
        cin >> d[i];
    }
    for (int i = 0; i <= m; ++i) {
        cin >> p[i];
    }
    map<string, int> price;
    for (int i = 0; i < m; ++i) {
        price[d[i]] = p[i + 1];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (price.count(c[i])) {
            ans += price[c[i]];
        } else {
            ans += p[0];
        }
    }
    cout << ans << '\n';
    return 0;
}
