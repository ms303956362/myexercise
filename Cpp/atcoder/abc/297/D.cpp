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
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    while (a != b) {
        if (a > b) {
            if (a % b != 0) {
                ans += a / b;
                a = a % b;
            } else {
                ans += (a - b) / b;
                a = b;
            }
        } else {
            if (b % a != 0) {
                ans += b / a;
                b = b % a;
            } else {
                ans += (b - a) / a;
                b = a;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
