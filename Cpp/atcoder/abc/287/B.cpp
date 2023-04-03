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
    int n, m;
    cin >> n >> m;
    vector<string> vs, vt;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        vs.push_back(s);
    }
    for (int i = 0; i < m; ++i) {
        string t;
        cin >> t;
        vt.push_back(t);
    }
    int ans = 0;
    for (const auto& s : vs) {
        for (const auto& t : vt) {
            if (s.substr(3, 3) == t) {
                ++ans;
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
