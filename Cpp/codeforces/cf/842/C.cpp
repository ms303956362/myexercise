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
    vector<vector<int>> idx(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        idx[x].push_back(i);
    }
    set<int> a, b;
    for (int i = 1; i <= n; ++i) {
        a.insert(i);
        b.insert(i);
    }
    vector<int> p(n), q(n);
    for (int i = 1; i <= n; ++i) {
        if (idx[i].size() > 2) {
            cout << "NO" << endl;
            return;
        } else if (idx[i].size() == 1) {
            p[idx[i][0]] = i;
            a.erase(i);
            auto ptr = b.upper_bound(i);
            if (ptr == b.begin()) {
                cout << "NO" << endl;
                return;
            }
            auto ptr1 = prev(ptr);
            q[idx[i][0]] = *ptr1;
            b.erase(ptr1);
        } else if (idx[i].size() == 2) {
            p[idx[i][0]] = i;
            q[idx[i][1]] = i;
            a.erase(i);
            b.erase(i);
            auto ptr = b.upper_bound(i);
            if (ptr == b.begin()) {
                cout << "NO" << endl;
                return;
            }
            auto ptr1 = prev(ptr);
            q[idx[i][0]] = *ptr1;
            b.erase(ptr1);
            auto ptr2 = a.upper_bound(i);
            if (ptr2 == a.begin()) {
                cout << "NO" << endl;
                return;
            }
            auto ptr3 = prev(ptr2);
            p[idx[i][1]] = *ptr3;
            a.erase(ptr3);
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << q[i] << " ";
    }
    cout << endl;
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
