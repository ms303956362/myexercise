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

using namespace std;

using ll = long long;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        unsigned long long l, r;
        cin >> l >> r;
        unsigned long long mask = (unsigned long long)(1 << 31) * (unsigned long long)(1 << 31) * 2;
        bool ok = false;
        for (unsigned long long i = 63; i >= 0; --i) {
            if ((l & mask) != (r & mask)) {
                ok = true;
                break;
            }
            if (i == 0) {
                break;
            }
            mask >>= 1;
        }
        if (!ok) {
            cout << l << endl;
        } else {
            if ((r & (mask - 1)) == (mask - 1)) {
                cout << r << endl;
            } else {
                cout << (l | (mask - 1)) << endl;
            }
        }
    }
    return 0;
}
