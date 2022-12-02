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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - 'a'];
    }
    string ans;
    for (int i = 0; i < k; ++i) {
        int p = 0, j = 0;
        char c = 'z';
        for (j = 0; j < n / k; ++j) {
            if (cnt[p] > 0) {
                --cnt[p];
                ++p;
            } else {
                
                break;
            }
        }
        c = p + 'a';
        ans.push_back(c);
    }
    cout << ans << endl;
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
