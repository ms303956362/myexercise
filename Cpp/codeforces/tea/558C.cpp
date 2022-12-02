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

int cnt[100005], ops[100005], vst[100005];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int max_num = *max_element(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        int num = a[i];
        int base = 0;
        while (num >= 1) {
            int x = num, c = base;
            while (x <= max_num) {
                if (vst[x] != i + 1) {
                    ++cnt[x];
                    ops[x] += c;
                    vst[x] = i + 1;
                }
                x <<= 1;
                ++c;
            }
            ++base;
            num >>= 1;
        }
    }
    int ans = INT_MAX;
    for (int x = 1; x < 100005; ++x) {
        int c = cnt[x];
        if (c == n) {
            ans = min(ans, ops[x]);
        }
    }
    cout << ans << endl;
    return 0;
}
