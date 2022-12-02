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
    ll h, w, k;
    cin >> h >> w >> k;
    vector<ll> a(h), b(w);
    ll sa = 0, sb = 0;
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
        sa += ((k - 1) * w - a[i]) % k;
    }
    for (int i = 0; i < w; ++i) {
        cin >> b[i];
        sb += ((k - 1) * h - b[i]) % k;
    }
    if (sa % k != sb % k) {
        cout << -1 << endl;
        return 0;
    }
    cout << h * w * (k - 1) - max(sa, sb) << endl;
    return 0;
}
