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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    auto calc = [&b, &n](const string& s) {
        ll ret = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                ret += (ll)b;
            }
            ++i;
            --j;
        }
        return ret;
    };
    ll ans = 0x3f3f3f3f3f3f3f3f, sum = 0;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, calc(s) + sum);
        string tmp = s.substr(1, n - 1);
        tmp.push_back(s[0]);
        s = tmp;
        sum += a;
    }
    cout << ans << endl;
    return 0;
}
