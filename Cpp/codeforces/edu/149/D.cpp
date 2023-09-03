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
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++cnt1;
        } else {
            ++cnt2;
        }
    }
    if (cnt1 != cnt2) {
        cout << -1 << '\n';
        return;
    }
    auto calc = [&n](string s) {
        vector<int> color(n, -1);
        stack<int> st;
        set<int> stt;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (!st.empty()) {
                color[st.top()] = 1;
                color[i] = 1;
                stt.insert(1);
                st.pop();
            }
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; --i) {
            if (color[i] == -1) {
                if (s[i] == '(') {
                    st.push(i);
                } else if (!st.empty()) {
                    color[st.top()] = 2;
                    color[i] = 2;
                    stt.insert(2);
                    st.pop();
                }
            }
        }
        return make_pair((int)stt.size(), color);
    };
    string t(s.rbegin(), s.rend());
    auto [c1, color1] = calc(s);
    auto [c2, color2] = calc(t);
    reverse(color2.begin(), color2.end());
    int cnt = min(c1, c2);
    vector<int> color = (c1 < c2 ? color1 : color2);
    cout << cnt << '\n';
    if (cnt == 1) {
        for (int i = 0; i < n; ++i) {
            cout << 1 << ' ';
        }
    } else {
        for (const auto& c : color) {
            cout << c << ' ';
        }
    }
    cout << '\n';
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
