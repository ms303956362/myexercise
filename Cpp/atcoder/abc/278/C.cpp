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
    unordered_map<int, unordered_set<int>> f;
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            f[a].insert(b);
        } else if (t == 2) {
            if (f[a].count(b)) {
                f[a].erase(b);
            }
        } else {
            cout << ((f[a].count(b) && f[b].count(a)) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}
