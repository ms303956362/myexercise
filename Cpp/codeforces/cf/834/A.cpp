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
    string s;
    cin >> s;
    int n = s.size(), j = -1;
    if (s[0] == 'Y') {
        j = 0;
    } else if (s[0] == 'e') {
        j = 1;
    } else if (s[0] == 's') {
        j = 2;
    }
    if (j == -1) {
        cout << "NO" << endl;
        return;
    }
    string t("Yes");
    for (int i = 0; i < n; ++i, j = (j + 1) % 3) {
        if (s[i] != t[j]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
