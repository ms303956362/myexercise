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
    string s;
    cin >> s;
    int q;
    cin >> q;
    BIT t(n + 1);
    vector<BIT> cnt(26, BIT(n + 1));
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - 'a'].update(i + 1, 1);
        if (i > 0) {
            t.update(i + 1, s[i] < s[i - 1]);
        }
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            char c;
            cin >> x >> c;
            --x;
            if (x > 0) {
                int old_val = (s[x] < s[x - 1]), new_val = (c < s[x - 1]);
                t.update(x + 1, new_val - old_val);
            }
            if (x + 1 < n) {
                int old_val = (s[x + 1] < s[x]), new_val = (s[x + 1] < c);
                t.update(x + 2, new_val - old_val);
            }
            cnt[s[x] - 'a'].update(x + 1, -1);
            cnt[c - 'a'].update(x + 1, 1);
            s[x] = c;
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            if (t.query(r + 1) - t.query(l + 1) > 0) {
                cout << "No" << '\n';
                continue;
            }
            bool ok = true;
            for (int k = s[l] - 'a' + 1; k < s[r] - 'a'; ++k) {
                if (cnt[k].query(r + 1) - cnt[k].query(l) != cnt[k].query(n)) {
                    cout << "No" << '\n';
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;
            }
            cout << "Yes" << "\n";
        }
    }
    return 0;
}
