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

map<int, int> sum2n;

void solve() {
    int m, s;
    cin >> m >> s;
    vector<int> b(m);
    int sb = 0;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        sb += b[i];
    }
    if (!sum2n.count(sb + s)) {
        cout << "NO" << endl;
        return;
    }
    int n = sum2n[sb + s];
    vector<bool> vst(n + 1);
    for (int i = 0; i < m; ++i) {
        if (b[i] < 1 || b[i] > n || vst[b[i]]) {
            cout << "NO" << endl;
            return;
        }
        vst[b[i]] = true;
    }
    cout << "YES" << endl;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int sum = 0;
    for (int i = 1; i <= 1000; ++i) {
        sum += i;
        sum2n[sum] = i;
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
