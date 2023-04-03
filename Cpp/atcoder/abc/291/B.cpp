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
    vector<int> x(5 * n);
    for (int i = 0; i < 5 * n; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    int sum = 0;
    for (int i = n; i < 4 * n; ++i) {
        sum += x[i];
    }
    cout << (double)sum / (3 * n) << '\n';
    return 0;
}
