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
    int t;
    cin >> t;
    auto check = [&](vector<int>& d, vector<int>& a) {
        int n = d.size();
        a[0] = d[0];
        for (int i = 1; i < n; ++i) {
            if (d[i] > 0 && a[i - 1] >= d[i]) {
                return false;
            }
            a[i] = a[i - 1] + d[i];
        }
        return true;
    };
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), d(n);
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }
        if (check(d, a)) {
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
