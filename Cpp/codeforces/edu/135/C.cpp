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

int a[200005], b[200005];


int dlog(int x) {
    int cnt = 0;
    while (x > 0) {
        ++cnt;
        x /= 10;
    }
    return cnt;
}

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
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        map<int, int> cnta, cntb;
        for (int i = 0; i < n; ++i) {
            ++cnta[a[i]];
            ++cntb[b[i]];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (cnta[a[i]] > 0 && cntb[a[i]] > 0) {
                --cnta[a[i]];
                --cntb[a[i]];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (cnta[a[i]] > 0 && a[i] >= 10) {
                ++ans;
                ++cnta[dlog(a[i])];
            }
            if (cntb[b[i]] > 0 && b[i] >= 10) {
                ++ans;
                ++cntb[dlog(b[i])];
            }
        }
        for (int x = 9; x > 1; --x) {
            if (cnta[x] > cntb[x]) {
                cnta[1] += cnta[x] - cntb[x];
            } else {
                cntb[1] += cntb[x] - cnta[x];
            }
            ans += abs(cnta[x] - cntb[x]);
        }
        ans += abs(cnta[1] - cntb[1]);
        cout << ans << endl;
    }
    return 0;
}
