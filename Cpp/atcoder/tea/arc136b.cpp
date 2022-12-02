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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    auto calc = [](vector<int>& a) {
        int n = a.size(), cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] > a[j]) {
                    ++cnt;
                }
            }
        }
        return cnt;
    };
    int ca = calc(a), cb = calc(b);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a != b) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << (((ca - cb) % 2 == 0) ? "Yes" : "No") << endl;
    return 0;
}
