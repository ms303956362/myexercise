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

vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string t;
    cin >> t;
    string x = t.substr(0, n), y = t.substr(n, n);
    reverse(y.begin(), y.end());
    vector<int> z1 = z_function(x + y), z2 = z_function(y + x);
    z1.push_back(0);
    z2.push_back(0);
    int j = -1;
    for (int i = 0; i <= n; ++i) {
        if (z1[2 * n - i] == i && z2[n + i] == n - i) {
            j = i;
            break;
        }
    }
    if (j != -1) {
        cout << t.substr(0, j) + t.substr(n + j, n - j) << endl;
    }
    cout << j << endl;
    return 0;
}
