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
        string s;
        cin >> s;
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '1') {
                continue;
            }
            ll cnt = 0;
            for (int j = 1; j * i <= n; ++j) {
                if (s[j * i - 1] == '0') {
                    ++cnt;
                    s[j * i - 1] = '2';
                } else if (s[j * i - 1] == '1') {
                    break;
                }
            }
            ans += cnt * i;
        }
        cout << ans << endl;
    }
    return 0;
}
