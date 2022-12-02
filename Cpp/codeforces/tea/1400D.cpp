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

int a[3005];

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
        map<int, long long> cnt;
        ++cnt[a[0]];
        long long ans = 0;
        for (int j = 1; j < n - 2; ++j) {
            long long c = cnt[a[j + 1]];
            for (int l = j + 2; l < n; ++l) {
                if (a[j] == a[l]) {
                    ans += c;
                }
                c += cnt[a[l]];
            }
            ++cnt[a[j]];
        }
        cout << ans << endl;
    }
    return 0;
}
