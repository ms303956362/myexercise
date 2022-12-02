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
    ll l, r;
    cin >> l >> r;
    ll mask = 1;
    for (int i = 0; i < 62; ++i) {
        mask *= 2;
    }
    while (mask > 0) {
        if ((l & mask) != (r & mask)) {
            break;
        }
        mask >>= 1;
    }
    ll ans = 0;
    while (mask > 0) {
        ans |= mask;
        mask >>= 1;
    }
    cout << ans << endl;
    return 0;
}
