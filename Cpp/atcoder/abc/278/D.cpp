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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    vector<vector<ll>> ops;
    for (int j = 0; j < q; ++j) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            ops.push_back(vector<ll>{1, x});
        } else if (t == 2) {
            int i, x;
            cin >> i >> x;
            --i;
            ops.push_back(vector<ll>{2, i, x});
        } else {
            int i;
            cin >> i;
            --i;
            ops.push_back(vector<ll>{3, i});
        }
    }
    int j = q - 1;
    vector<ll> ans;
    while (j >= 0) {
        while (j >= 0 && ops[j][0] != 1) {
            --j;
        }
        unordered_map<int, ll> addition;
        if (j < 0) {
            int k = j + 1;
            ll len = ans.size();
            while (k < q && ops[k][0] != 1) {
                if (ops[k][0] == 2) {
                    addition[ops[k][1]] += ops[k][2];
                } else {
                    ans.push_back(a[ops[k][1]] + addition[ops[k][1]]);
                }
                ++k;
            }
            reverse(ans.begin() + len, ans.end());
        } else {
            ll x = ops[j][1];
            int k = j + 1;
            ll len = ans.size();
            while (k < q && ops[k][0] != 1) {
                if (ops[k][0] == 2) {
                    addition[ops[k][1]] += ops[k][2];
                } else {
                    ans.push_back(x + addition[ops[k][1]]);
                }
                ++k;
            }
            reverse(ans.begin() + len, ans.end());
        }
        --j;
    }
    int m = ans.size();
    for (int i = m - 1; i >= 0; --i) {
        cout << ans[i] << endl;
    }
    return 0;
}
