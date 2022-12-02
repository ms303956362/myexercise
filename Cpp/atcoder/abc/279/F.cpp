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

int p[1000005];
int idx2rep[1000005], rep2idx[1000005];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < 1000005; ++i) {
        p[i] = i;
        idx2rep[i] = i;
        rep2idx[i] = i;
    }
    function<int(int)> find = [&](int u) {
        return p[u] == u ? u : (p[u] = find(p[u]));
    };
    auto merge = [&](int i1, int i2) {
        if (idx2rep[i2] == -1) {
            return;
        }
        if (idx2rep[i1] == -1) {
            idx2rep[i1] = idx2rep[i2];
            rep2idx[idx2rep[i1]] = i1;
            idx2rep[i2] = -1;
            return;
        }
        idx2rep[i1] = find(idx2rep[i1]);
        idx2rep[i2] = find(idx2rep[i2]);
        p[idx2rep[i2]] = idx2rep[i1];
        idx2rep[i2] = -1;
    };
    int k = n + 1;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            merge(x, y);
        } else if (t == 2) {
            int x;
            cin >> x;
            merge(x, k);
            ++k;
        } else {
            int x;
            cin >> x;
            cout << rep2idx[find(x)] << '\n';
        }
    }
    return 0;
}
