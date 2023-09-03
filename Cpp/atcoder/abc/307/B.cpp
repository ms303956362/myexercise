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
    vector<string> v;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    auto check = [&](int i, int j) {
        string s = v[i] + v[j];
        int l = s.size(), k = 0;
        while (k < l - k - 1) {
            if (s[k] != s[l - k - 1]) {
                return false;
            }
            ++k;
        }
        return true; 
    };
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                continue;
            }
            if (check(i, j)) {
                ok = true;
                break;
            }
        }
        if (ok) {
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}
