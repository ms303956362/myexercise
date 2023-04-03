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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v1, v2;
    v1.emplace_back(-1, 0);
    for (int i = 0; i < n; ++i) {
        int t, y;
        cin >> t >> y;
        if (t == 1) {
            v1.emplace_back(i, y);
        } else {
            v2.emplace_back(i, y);
        }
    }
    priority_queue<int> q;
    int m1 = v1.size(), m2 = v2.size(), cnt = 0;
    ll ans = -1e18, sum = 0;
    for (int i = m1 - 1, j = m2 - 1; i >= 0 && cnt <= k; --i, ++cnt) {
        ll x = v1[i].second;
        if (q.size() > k - cnt) {
            sum += q.top();
            q.pop();
        }
        while (j >= 0 && v2[j].first >= v1[i].first) {
            int y = v2[j].second;
            if (y >= 0) {
                sum += y;
            } else {
                if (q.size() < k - cnt) {
                    q.push(y);
                } else {
                    if (q.empty() || y >= q.top()) {
                        sum += y;
                    } else {
                        sum += q.top();
                        q.pop();
                        q.push(y);
                    }
                }
            }
            --j;
        }
        ans = max(ans, x + sum);
    }
    cout << ans << endl;
    return 0;
}
