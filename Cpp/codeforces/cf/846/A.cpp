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
    int n;
    cin >> n;
    vector<int> a0, a1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x % 2) {
            a1.push_back(i + 1);
        } else {
            a0.push_back(i + 1);
        }
    }
    if ((a1.size() >= 1 && a0.size() >= 2) || (a1.size() >= 3)) {
        cout << "Yes" << '\n';
        if (a1.size() >= 1 && a0.size() >= 2) {
            cout << a1[0] << " " << a0[0] << " " << a0[1] << '\n';
        } else {
            cout << a1[0] << " " << a1[1] << " " << a1[2] << '\n';
        }
    } else {
        cout << "No" << '\n';
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
