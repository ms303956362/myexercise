// IO
#include <iostream>
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
#include <ostream>
using namespace std;

using ll = long long;

int main(int argc, char const *argv[])
{
    ll l = 3, h = 1e18 + 5;
    while (l <= h) {
        ll n = (l + h) / 2;
        cout << "? " << 1 << " " << n << endl;
        ll ans;
        cin >> ans;
        if (ans == 0) {
            break;
        }
        if (ans == -1) {
            h = n - 1;
        } else {
            l = max(ans + 1, n + 1);
        }
    }
    cout << "! " << h << endl;
    return 0;
}
