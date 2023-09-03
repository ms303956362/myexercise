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
    int n;
    cin >> n;
    vector<ll> p{1, 101, 101 * 101, 101 * 101 * 101, 101 * 101 * 101 * 101, 101 * 101 * 101 * 101 * 101};
    auto plane2ll = [&p](vector<ll> v) {
        ll ret = 0;
        for (int i = 0; i < 6; ++i) {
            ret += v[i] * p[i];
        }
        return ret;
    };
    auto gen_plane = [](vector<ll> p1, vector<ll> p2) {
        vector<vector<ll>> ret;
        for (int k = 0; k < 3; ++k) {
            vector<ll> v1(p1), v2(p2);
            v1[k] = p1[k];
            v2[k] = p1[k];
            ret.push_back(vector<ll>());
            for (int i = 0; i < 3; ++i) {
                ret.back().push_back(v1[i]);
            }
            for (int i = 0; i < 3; ++i) {
                ret.back().push_back(v2[i]);
            }
            v1[k] = p2[k];
            v2[k] = p2[k];
            ret.push_back(vector<ll>());
            for (int i = 0; i < 3; ++i) {
                ret.back().push_back(v1[i]);
            }
            for (int i = 0; i < 3; ++i) {
                ret.back().push_back(v2[i]);
            }
        }
        return ret;
    };
    map<ll, int> cnt;
    vector<vector<ll>> planesll(n);
    for (int i = 0; i < n; ++i) {
        vector<ll> p1(3), p2(3);
        for (int j = 0; j < 3; ++j) {
            cin >> p1[j];
        }
        for (int j = 0; j < 3; ++j) {
            cin >> p2[j];
        }
        auto planes = gen_plane(p1, p2);
        for (const auto& plane : planes) {
            ll l = plane2ll(plane);
            ++cnt[l];
            planesll[i].push_back(l);
        }
    }
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (const auto& l : planesll[i]) {
            ans += cnt[l] - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
