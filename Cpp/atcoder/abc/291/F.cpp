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
    int n, m;
    cin >> n >> m;
    vector<string> v(n), v2(n, string(m, '0'));
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == '1') {
                v2[i + j + 1][j] = '1';
            }
        }
    }
    vector<int> dis1(n, -1), dis2(n, -1);
    queue<int> q1, q2;
    vector<bool> vst1(n), vst2(n);
    q1.push(0);
    vst1[0] = true;
    int step = 0;
    while (!q1.empty()) {
        int l = q1.size();
        while(l--) {
            auto i = q1.front();
            q1.pop();
            dis1[i] = step;
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == '1' && !vst1[i + j + 1]) {
                    vst1[i + j + 1] = true;
                    q1.push(i + j + 1);
                }
            }
        }
        ++step;
    }
    q2.push(n - 1);
    vst2[n - 1] = true;
    step = 0;
    while (!q2.empty()) {
        int l = q2.size();
        while (l--) {
            auto i = q2.front();
            q2.pop();
            dis2[i] = step;
            for (int j = 0; j < m; ++j) {
                if (v2[i][j] == '1' && !vst2[i - j - 1]) {
                    vst2[i - j - 1] = true;
                    q2.push(i - j - 1);
                }
            }
        }
        ++step;
    }
    vector<int> ans;
    for (int k = 1; k < n - 1; ++k) {
        int d = 0x3f3f3f3f;
        for (int i = max(k - m + 1, 0); i < k; ++i) {
            for (int j = k + 1; j - i <= m; ++j) {
                if (v[i][j - i - 1] == '1' && dis1[i] != -1 && dis2[j] != -1) {
                    d = min(d, dis1[i] + dis2[j] + 1);
                }
            }
        }
        if (d < 0x3f3f3f3f) {
            ans.push_back(d);
        } else {
            ans.push_back(-1);
        }
    }
    for (const auto& d : ans) {
        cout << d << "\n";
    }
    return 0;
}
