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
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> right_min(n);
        right_min[n - 1] = s[n - 1] - '0';
        for (int i = n - 2; i >= 0; --i) {
            right_min[i] = min(s[i] - '0', right_min[i + 1]);
        }
        vector<int> cnt(10);
        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            if (d == right_min[i]) {
                ++cnt[d];
            } else {
                ++cnt[min(d + 1, 9)];
            }
        }
        for (int i = 0; i <= 9; ++i) {
            cout << string(cnt[i], i + '0');
        }
        cout << endl;
    }
    return 0;
}
