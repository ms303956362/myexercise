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

void solve() {
    int n;
    string s;
    cin >> n >> s;
    auto check = [&]() {
        int cntq = 0, cnta = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == 'A') {
                ++cnta;
            } else {
                ++cntq;
                if (cntq > cnta) {
                    return false;
                }
            }
        }
        return true;
    };
    if (check()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
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
