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

void solve() {
    int n;
    cin >> n;
    auto generate = [](int n) {
        vector<int> ans;
        for (int i = 1; i <= n / 2; i += 2) {
            ans.push_back(n / 2 + i);
            ans.push_back(i);
            if (i + 1 <= n / 2) {
                ans.push_back(n / 2 + i + 1);
                ans.push_back(i + 1);
            }
        }
        return ans;
    };
    vector<int> ans;
    if (n % 2 == 0) {
        ans = generate(n);
    } else {
        ans = generate(n - 1);
        ans.push_back(n);
    }
    for (const auto& num : ans) {
        cout << num << " ";
    }
    cout << endl;
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
