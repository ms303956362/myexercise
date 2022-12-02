// IO
#include <iostream>
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
    int t;
    cin >> t;
    auto check = [](vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<int> cnt_same_r(m), cnt_l(m);
        int cnt = 0;
        for (int i = m - 1, j = n - 1; i >= 0; --i, --j) {
            cnt_same_r[i] = cnt;
            while (j >= 0 && a[j] > b[i]) {
                --j;
            }
            if (j >= 0 && a[j] == b[i]) {
                ++cnt;
            }
        }
        for (int i = 0, j = 0; i < m; ++i) {
            while (j < n && a[j] <= b[i]) {
                ++j;
            }
            int k = b.begin() + i - upper_bound(b.begin(), b.end(), b[i] - j) + 1;
            cnt_l[i] = k;
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            ans = max(ans, cnt_same_r[i] + cnt_l[i]);
        }
        return ans;
    };
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a_neg, a_pos, b_neg, b_pos;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x < 0) {
                a_neg.push_back(-x);
            } else {
                a_pos.push_back(x);
            }
        }
        reverse(a_neg.begin(), a_neg.end());
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            if (x < 0) {
                b_neg.push_back(-x);
            } else {
                b_pos.push_back(x);
            }
        }
        reverse(b_neg.begin(), b_neg.end());
        cout << check(a_neg, b_neg) + check(a_pos, b_pos) << endl;
    }
    return 0;
}
