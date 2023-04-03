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

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(10);
    for (int i = 0; i < 4; ++i) {
        ++cnt[s[i] - '0'];
    }
    int max_cnt = 0;
    for (int i = 0; i < 10; ++i) {
        max_cnt = max(max_cnt, cnt[i]);
    }
    if (max_cnt == 1 || max_cnt == 2) {
        cout << 4 << '\n';
    } else if (max_cnt == 3) {
        cout << 6 << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
