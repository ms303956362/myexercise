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

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<ll, vector<ll>, greater<ll>> q1;
    priority_queue<ll> q2, q3;
    multiset<ll> st;
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int t, x;
        cin >> t >> x;
        if (t == 0) {
            ans += x;
            q1.push(x);
            st.insert(x);
        } else if (t == 1) {
            q2.push(x);
        } else {
            q3.push(x);
        }
    }
    while (st.size() > m) {
        auto x = q1.top();
        q1.pop();
        st.erase(st.begin());
        ans -= x;
    }
    ll sum = ans, quota = 0, cnt1 = q1.size(), cnt2 = 0, cnt3 = 0;
    while (!q2.empty()) {
        if (quota == 0) {
            if (q3.empty()) {
                break;
            }
            if (cnt1 + cnt2 + cnt3 >= m) {
                if (q1.empty()) {
                    break;
                }
                auto x = q1.top();
                q1.pop();
                sum -= x;
                --cnt1;
            }
            quota = q3.top();
            q3.pop();
            ++cnt3;
        }
        while (cnt1 + cnt2 + cnt3 < m && quota > 0) {
            auto x = q2.top();
            q2.pop();
            sum += x;
            ++cnt2;
            --quota;
        }
        while (!q1.empty() && !q2.empty() && q1.top() < q2.top() && quota > 0) {
            auto x = q1.top();
            q1.pop();
            sum -= x;
            --cnt1;
            x = q2.top();
            q2.pop();
            sum += x;
            ++cnt2;
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}
