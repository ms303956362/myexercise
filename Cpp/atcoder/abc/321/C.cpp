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
    vector<ll> a;
    string s;
    function<void(int)> backtrack = [&](int i) {
        if (i == 10) {
            if (!s.empty()) {
                ll num = stoll(s);
                // cout << num << " ";
                if (num > 0) {
                    a.push_back(num);
                }
            }
            return;
        }
        backtrack(i + 1);
        s.push_back(9 - i + '0');
        backtrack(i + 1);
        s.pop_back();
    };
    backtrack(0);
    sort(a.begin(), a.end());
    ll k;
    cin >> k;
    cout << a[k - 1] << endl;
    return 0;
}
