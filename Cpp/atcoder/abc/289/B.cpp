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
    vector<bool> has(n + 1);
    for (int j = 0; j < m; ++j) {
        int a;
        cin >> a;
        has[a] = true;
    }
    int i = 1;
    while (i <= n) {
        vector<int> b;
        while (i <= n && has[i]) {
            b.push_back(i);
            ++i;
        }
        if (i <= n) {
            b.push_back(i);
        }
        reverse(b.begin(), b.end());
        for (const auto& num : b) {
            cout << num << " ";
        }
        ++i;
    }
    cout << '\n';
    return 0;
}
