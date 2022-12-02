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
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        b[i] = i;
    }
    vector<int> alter(m);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (b[x] == 1) {
            alter[i] = b[x + 1];
        } else if (b[x + 1] == 1) {
            alter[i] = b[x];
        } else {
            alter[i] = 1;
        }
        swap(b[x], b[x + 1]);
    }
    vector<int> idx(n + 1);
    for (int i = 1; i <= n; ++i) {
        idx[b[i]] = i;
    }
    for (int i = 0; i < m; ++i) {
        cout << idx[alter[i]] << "\n";
    }
    cout << endl;
    return 0;
}
