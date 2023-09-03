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
    vector<int> pb(2), pr(2);
    int xk = 0, ib = 0, ir = 0;
    for (int i = 0; i < 8; ++i) {
        if (s[i] == 'B') {
            pb[ib] = i + 1;
            ++ib;
        } else if (s[i] == 'R') {
            pr[ir] = i + 1;
            ++ir;
        } else if (s[i] == 'K') {
            xk = i + 1;
        }
    }
    cout << ((pb[0] % 2 != pb[1] % 2 && pr[0] < xk && xk < pr[1]) ? "Yes" : "No") << '\n';
    return 0;
}
