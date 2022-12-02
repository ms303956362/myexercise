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

int aa[300005];
// int a[300005];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> aa[i];
    }
    aa[n] = m - 1;
    int l = 0, h = m;
    auto check = [&](int k) -> bool {
        vector<int> a(n + 1);
        for (int i = 0; i <= n; ++i) {
            a[i] = aa[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] > a[i + 1]) {
                if (a[i] + k < m) {
                    return false;
                }
                a[i] = min((a[i] + k) % m, a[i + 1]);
            } else {
                a[i] = min(a[i] + k, a[i + 1]);
            }
        }
        return true;
    };
    while (l <= h) {
        int k = (l + h) / 2;
        if (check(k)) {
            h = k - 1;
        } else {
            l = k + 1;
        }
    }
    cout << l << endl;
    return 0;
}
