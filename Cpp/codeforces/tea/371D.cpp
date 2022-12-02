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

ll a[200005], b[200005];
int p[200005];

int find(int x) {
    return p[x] == x ? x : (p[x] = find(p[x]));
}

void unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) {
        return;
    }
    p[px] = py;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    p[n] = n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[i] = i;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            ll p, x;
            cin >> p >> x;
            --p;
            int f = find(p);
            while (f < n && x > 0) {
                if (b[f] + x < a[f]) {
                    b[f] += x;
                    break;
                } else {
                    x -= a[f] - b[f];
                    b[f] = a[f];
                    unite(f, f + 1);
                    ++f;
                }
            }
        } else {
            ll k;
            cin >> k;
            --k;
            cout << b[k] << endl;
        }
    }
    return 0;
}
