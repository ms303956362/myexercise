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
    string s, t;
    cin >> s >> t;
    int m = s.size(), n = t.size();
    vector<bool> dp1(n + 1), dp2(n + 1);
    dp1[0] = true;
    dp2[0] = true;
    for (int i = 0; i < n; ++i) {
        if ((s[i] == t[i] || s[i] == '?' || t[i] == '?') && dp1[i]) {
            dp1[i + 1] = true;
        } else {
            dp1[i + 1] = false;
        }
        if ((s[m - i - 1] == t[n - i - 1] || s[m - i - 1] == '?' || t[n - i - 1] == '?') && dp2[i]) {
            dp2[i + 1] = true;
        } else {
            dp2[i + 1] = false;
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (dp1[i] && dp2[n - i]) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
    return 0;
}
