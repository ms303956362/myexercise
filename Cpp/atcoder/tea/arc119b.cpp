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
    string s, t;
    cin >> s >> t;
    vector<int> vs, vt;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            vs.push_back(i);
        }
        if (t[i] == '0') {
            vt.push_back(i);
        }
    }
    if (vs.size() != vt.size()) {
        cout << -1 << endl;
        return 0;
    }
    int m = vs.size(), ans = 0;
    for (int i = 0; i < m; ++i) {
        if (vs[i] != vt[i]) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
