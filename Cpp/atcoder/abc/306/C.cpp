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
    int n;
    cin >> n;
    vector<vector<int>> idx(n + 1);
    for (int i = 0; i < 3 * n; ++i) {
        int x;
        cin >> x;
        idx[x].push_back(i + 1);
    }
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; ++i) {
        v.emplace_back(idx[i][1], i);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        cout << v[i].second << ' ';
    }
    cout << '\n';
    return 0;
}
