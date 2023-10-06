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
    int n, x;
    cin >> n >> x;
    vector<int> a;
    for (int i = 0; i < n - 1; ++i) {
        int num;
        cin >> num;
        a.push_back(num);
    }
    sort(a.begin(), a.end());
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n - 2; ++i) {
        sum1 += a[i];
    }
    for (int i = 1; i < n - 1; ++i) {
        sum2 += a[i];
    }
    if (x > sum2) {
        cout << -1 << '\n';
        return 0;
    }
    if (x <= sum1) {
        cout << 0 << '\n';
        return 0;
    }
    cout << x - (sum1 - a[0]) << '\n';
    return 0;
}
