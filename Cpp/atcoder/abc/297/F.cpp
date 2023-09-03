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
    int n, d;
    cin >> n >> d;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    for (int i = 1; i < n; ++i) {
        if (v[i] - v[i - 1] <= d) {
            cout << v[i] << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
