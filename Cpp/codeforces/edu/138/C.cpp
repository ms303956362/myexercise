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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    auto check = [&](int k) -> bool {
        list<int> l(a.begin(), a.end());
        for (int i = 0; i < k; ++i) {
            if (l.empty()) {
                return false;
            }
            while (!l.empty() && l.back() > k - i) {
                l.pop_back();
            }
            if (l.empty()) {
                return false;
            }
            l.pop_back();
            if (!l.empty()) {
                l.pop_front();
            }
        }
        return true;
    };
    for (int k = n; k >= 0; --k) {
        if (check(k)) {
            cout << k << endl;
            break;
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
