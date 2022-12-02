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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    map<int, pair<int, int>> mp;    // sb: [eb, sa]
    for (int i = 0; i < m; ++i) {
        int op;
        cin >> op;
        if (op == 2) {
            int x;
            cin >> x;
            auto p = mp.upper_bound(x);
            if (p == mp.begin()) {
                cout << b[x] << endl;
                continue;
            }
            p = prev(p);
            auto [s, pr] = *p;
            auto [e, beg] = pr;
            if (x <= e) {
                cout << a[beg + x - s] << endl;
            } else {
                cout << b[x] << endl;
            }
        } else {
            int sa, sb, l;
            cin >> sa >> sb >> l;
            int eb = sb + l - 1;
            auto p = mp.upper_bound(sb);
            if (p != mp.begin()) {
                p = prev(p);
            }
            while (p != mp.end() && p->first <= eb) {
                auto q = next(p);
                auto [s, pr] = *p;
                auto [e, b] = pr;
                mp.erase(p);
                if (s < sb) {
                    mp[s] = make_pair(min(e, sb - 1), b);
                }
                if (e > eb) {
                    mp[eb + 1] = make_pair(e, b + eb + 1 - s);
                }
                p = q;
            }
            mp[sb] = make_pair(eb, sa);
        }
    }
    return 0;
}
/*
10 10
30309104 549112629 140680174 -388626136 250601625 -858419311 -816615815 546026161 931549839 769166551
-947536949 480016966 896206679 -236821505 753749116 -732369212 284781470 412891161 361791172 -100696163
1 10 4 1
2 1
1 5 9 2
1 5 6 2
2 5
1 10 10 1
1 4 10 1
2 6
2 9
2 10
*/
