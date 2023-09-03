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

void solve() {
    string n1, n2;
    cin >> n1 >> n2;
    auto padding = [](string& s, int n) {
        reverse(s.begin(), s.end());
        while (s.size() < n) {
            s.push_back('0');
        }
        reverse(s.begin(), s.end());
    };
    if (n1.size() < n2.size()) {
        padding(n1, n2.size());
    }
    if (n2.size() < n1.size()) {
        padding(n2, n1.size());
    }
    if (n2 < n1) {
        swap(n1, n2);
    }
    int n = n1.size();
    for (int i = 0; i < n; ++i) {
        if (n1[i] != n2[i]) {
            cout << (n2[i] - n1[i]) + 9 * (n - i - 1) << '\n';
            return;
        }
    }
    cout << 0 << '\n';
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
