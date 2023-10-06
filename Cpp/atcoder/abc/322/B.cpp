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
#include <numeric>
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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    string pre = t.substr(0, n), suf = t.substr(m - n, n);
    if (pre == s && suf == s) {
        cout << 0 << '\n';
    } else if (pre == s) {
        cout << 1 << '\n';
    } else if (suf == s) {
        cout << 2 << '\n';
    } else {
        cout << 3 << '\n';
    }
    return 0;
}
