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
    int n, q;
    cin >> n >> q;
    vector<int> cnty(n), cntr(n);
    for (int i = 0; i < q; ++i) {
        int t, x;
        cin >> t >> x;
        --x;
        if (t == 1) {
            ++cnty[x];
        } else if (t == 2) {
            ++cntr[x];
        } else {
            cout << ((cnty[x] >= 2 || cntr[x] >= 1) ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}
