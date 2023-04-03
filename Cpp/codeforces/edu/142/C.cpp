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

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), idx(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        idx[p[i]] = i;
    }
    set<int> st;
    if (n % 2 == 1) {
        st.insert(idx[n / 2 + 1]);
    }
    int a = n / 2, b = 1 + n - a, cnt = 0;
    while (a >= 1) {
        if (st.empty() || idx[a] < *st.begin()) {
            st.insert(idx[a]);
        } else {
            break;
        }
        if (st.empty() || idx[b] > *st.rbegin()) {
            st.insert(idx[b]);
        } else {
            break;
        }
        --a;
        ++b;
        ++cnt;
    }
    cout << n / 2 - cnt << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
