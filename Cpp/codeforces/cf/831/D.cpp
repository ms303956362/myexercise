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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    priority_queue<int> q;
    int num = k;
    for (int i = 0; i < k; ++i) {
        int sz = q.size();
        if (sz >= n * m - 3) {
            cout << "TIDAK" << endl;
            return;
        }
        bool used = false;
        if (a[i] == num) {
            --num;
            used = true;
        }
        while (!q.empty() && q.top() == num) {
            --num;
            q.pop();
        }
        // cout << i << ": " << num << endl;
        if (!used) {
            q.push(a[i]);
        }
    }
    int sz = q.size();
    if (sz > n * m - 3) {
        cout << "TIDAK" << endl;
        return;
    }
    cout << "YA" << endl;
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
