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
    vector<ll> cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                if (j * j == i) {
                    ++cnt[i];
                } else {
                    cnt[i] += 2;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += cnt[i] * cnt[n - i];
    }
    cout << ans << '\n';
    return 0;
}
