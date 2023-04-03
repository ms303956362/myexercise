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
#define PI 3.14159265358979323846

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long double a, b;
    cin >> a >> b;
    if (a < b) {
        swap(a, b);
    }
    if (sqrt(3) * a > 2 * b) {
        cout << setprecision(20) << 2 * sqrt(3) * b / 3 << '\n';
    } else {
        long double l = 0, h = PI / 6;
        while (abs(l - h) > 1e-12) {
            long double m = (l + h) / 2;
            long double lb = b / cosl(m), la = a / cosl(PI / 6 - m);
            if (lb < la) {
                l = m;
            } else {
                h = m;
            }
        }
        cout << setprecision(20) << b / cosl((l + h) / 2) << '\n';
    }
    return 0;
}
