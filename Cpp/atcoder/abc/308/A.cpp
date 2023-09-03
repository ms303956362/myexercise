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
    int s;
    vector<int> v;
    bool ok = true;
    for (int i = 0; i < 8; ++i) {
        cin >> s;
        if (!(100 <= s && s <= 675 && s % 25 == 0)) {
            ok = false;
        }
        v.push_back(s);
    }
    if (!ok) {
        cout << "No" << '\n';
        return 0;
    }
    vector<int> v1(v);
    sort(v1.begin(), v1.end());
    if (v != v1) {
        cout << "No" << '\n';
        return 0;
    }
    cout << "Yes" << '\n';
    return 0;
}
