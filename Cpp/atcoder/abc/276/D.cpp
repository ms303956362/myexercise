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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int g = a[0];
    for (int i = 1; i < n; ++i) {
        g = __gcd(g, a[i]);
    }
    auto check = [&]() -> int {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int f = a[i] / g;
            while (f % 2 == 0) {
                f /= 2;
                ++cnt;
            }
            while (f % 3 == 0) {
                f /= 3;
                ++cnt;
            }
            if (f != 1) {
                return -1;
            }
        }
        return cnt;
    };
    std::cout << check() << endl;
    return 0;
}
