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
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ll l, r, k = n - i;
        cin >> l >> r;
        if (l > r) {
            swap(l, r);
        }
        ans += k * (k + 1) / 2 - l * (n - r + 1);
    }
    ++ans;
    cout << ans << endl;
    return 0;
}
