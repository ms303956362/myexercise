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

void solve() {
    int n;
    cin >> n;
    int cntn = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x < 0) {
            ++cntn;
        }
    }
    int cntne = n / 2;
    if (cntne % 2 == 1) {
        --cntne;
    }
    if (cntn <= cntne) {
        cout << (cntn % 2 == 0 ? 0 : 1) << '\n';
        return;
    }
    cout << cntn - cntne << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
