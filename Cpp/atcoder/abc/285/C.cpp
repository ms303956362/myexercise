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
    string s;
    cin >> s;
    auto get_s = [](ll m) {
        
        string t;
        while (m > 0) {
            --m;
            t.push_back('A' + m % 26);
            m /= 26;
        }
        reverse(t.begin(), t.end());
        return t;
    };
    ll l = 1, h = 1e16 + 5;
    ll ans = 1;
    while (l <= h) {
        ll m = (l + h) / 2;
        string t = get_s(m);
        // cout << m << " " << t << endl;
        if (t.size() < s.size() || (t.size() == s.size() && t < s)) {
            l = m + 1;
        } else if (t.size() > s.size() || (t.size() == s.size() && t > s)) {
            h = m - 1;
        } else {
            ans = m;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}
