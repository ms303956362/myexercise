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

using ll = unsigned long long;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> a(64);
    for (int i = 0; i < 64; ++i) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < 64; ++i) {
        ans = ans * 2 + a[i];
    }
    cout << ans << '\n';
    return 0;
}
