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

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> y[i];
        }
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            d[i] = x[i] - y[i];
        }
        sort(d.begin(), d.end());
        int ans = 0, i = 0, j = n - 1;
        while (i < j) {
            while (i < j && d[i] + d[j] > 0) {
                --j;
            }
            if (i < j) {
                ++ans;
                ++i;
                --j;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
