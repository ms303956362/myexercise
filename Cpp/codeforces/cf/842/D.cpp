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
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i + 1];
    }
    vector<bool> vst(n + 1);
    bool ok = false;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vst[i]) {
            vector<int> idx;
            int k = i;
            while (!vst[k]) {
                idx.push_back(k);
                vst[k] = true;
                k = p[k];
            }
            sort(idx.begin(), idx.end());
            int m = idx.size();
            for (int i = 0; i < m - 1; ++i) {
                if (idx[i] + 1 == idx[i + 1]) {
                    ok = true;
                    break;
                }
            }
            ++cnt;
        }
    }
    cout << (ok ? (n - cnt - 1) : (n - cnt + 1)) << endl;
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
