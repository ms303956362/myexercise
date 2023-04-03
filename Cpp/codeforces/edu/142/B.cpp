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
    ll a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    ll s1 = 0, s2 = 0, s3 = 0;
    if (a1 > 0) {
        s1 = a1;
        if (a2 > a3) {
            swap(a2, a3);
        }
        s2 = a2 * 2;
        s3 = min(a3 - a2 + a4, a1 + 1);
    } else {
        s1 = 1;
    }
    cout << s1 + s2 + s3 << '\n';
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
