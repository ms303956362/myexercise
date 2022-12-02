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

int a[2005];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = -1000;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, a[i] - a[(i + 1) % n]);
        }
        int min_num = 1000, max_num  = 0;
        for (int i = 0; i < n - 1; ++i) {
            min_num = min(min_num, a[i]);
        }
        for (int i = 1; i < n; ++i) {
            max_num = max(max_num, a[i]);
        }
        ans = max({ans, max_num - a[0], a[n - 1] - min_num});
        cout << ans << endl;
    }
    return 0;
}
