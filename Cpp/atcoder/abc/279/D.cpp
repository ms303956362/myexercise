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
    cout << fixed << setprecision(12);
    double A, B;
    cin >> A >> B;
    auto time = [&](ll g) {
        if (g < 0) {
            return 1e30;
        }
        return g * B + A / sqrt(g + 1);
    };
    double k = pow(A / (2 * B), 2.0 / 3.0) - 1;
    ll kk = k;
    double ans = 1e30;
    for (ll i = max((ll)0, kk - 10000); i < kk + 10000; ++i) {
        ans = min(ans, time(i));
    }
    cout << ans << endl;
    return 0;
}
