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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cntt = 0, cnta = 0;
    char ans;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'T') {
            ++cntt;
        } else {
            ++cnta;
        }
        if (cnta > cntt) {
            ans = 'A';
        }
        if (cntt > cnta) {
            ans = 'T';
        }
    }
    cout << ans << '\n';
    return 0;
}
