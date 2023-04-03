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
    vector<int> a(n), b(m), idx_a(n), idx_b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int i = 0, j = 0, k = 1;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            idx_a[i] = k;
            ++i;
        } else {
            idx_b[j] = k;
            ++j;
        }
        ++k;
    }
    while (i < n) {
        idx_a[i] = k;
        ++i;
        ++k;
    }
    while (j < m) {
        idx_b[j] = k;
        ++j;
        ++k;
    }
    for (int i = 0; i < n; ++i) {
        cout << idx_a[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < m; ++i) {
        cout << idx_b[i] << ' ';
    }
    cout << '\n';
    return 0;
}
