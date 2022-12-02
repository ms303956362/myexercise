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
    string a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "=" << endl;
        return;
    }
    int n = a.size(), m = b.size();
    vector<int> level(256);
    level['S'] = 0;
    level['M'] = 1;
    level['L'] = 2;
    if (level[a[n - 1]] < level[b[m - 1]]) {
        cout << "<" << endl;
    } else if (level[a[n - 1]] > level[b[m - 1]]) {
        cout << ">" << endl;
    } else {
        if (a.size() == b.size()) {
            cout << "=" << endl;
        } else if (a.size() > b.size()) {
            cout << (a[n - 1] == 'L' ? ">" : "<") << endl;
        } else {
            cout << (a[n - 1] == 'L' ? "<" : ">") << endl;
        }
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
