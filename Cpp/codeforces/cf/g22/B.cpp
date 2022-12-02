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

bool check(int n, int k, vector<ll>& s) {
    ll last = INT_MAX;
    for (int i = k - 1; i > 0; --i) {
        if (s[i] - s[i - 1] > last) {
            return false;
        }
        last = s[i] - s[i - 1];
    }
    for (int i = 0; i < n - k; ++i) {
        s[0] -= last;
    }
    return s[0] <= last;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> s(k);
        for (int i = 0; i < k; ++i) {
            cin >> s[i];
        }
        if (check(n, k, s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
