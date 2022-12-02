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

class BIT {
    int n;
    vector<int> tree;
public:
    BIT(int _n) : n(_n + 1), tree(_n + 1, 0) {}
    BIT(const vector<int>& a) : n(a.size() + 1), tree(a.size() + 1, 0) {
        for (int i = 1; i < n; ++i) {
            update(i - 1, a[i - 1]);
        }
    }

    inline int lowBit(int i) { return i & (-i); }

    void update(int i, int delta) {
        ++i;
        while (i < n) {
            tree[i] += delta;
            i += lowBit(i);
        }
    }

    int query(int i) {
        ++i;
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= lowBit(i);
        }
        return sum;
    }

};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    unordered_map<int, vector<int>> idx;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] += i;
        idx[a[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        b[i] += i;
    }
    for (auto& [_, v] : idx) {
        reverse(v.begin(), v.end());
    }
    ll ans = 0;
    BIT t(n);
    for (int i = 0; i < n; ++i) {
        if (idx[b[i]].empty()) {
            cout << -1 << endl;
            return 0;
        }
        int j = idx[b[i]].back();
        idx[b[i]].pop_back();
        ans += (ll)(i - t.query(j));
        t.update(j, 1);
    }
    cout << ans << endl;
    return 0;
}
