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
        int n, c;
        cin >> n >> c;
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ++cnt[a];
        }
        int ans = 0;
        for (const auto& [a, ct] : cnt) {
            ans += min(ct, c);
        }
        cout << ans << endl;
    }
    return 0;
}
