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
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n - 1; ++j) {
            if (s[j] == 'T' && s[j + 1] == 'T') {
                s[j] = 'P';
                s[j + 1] = 'C';
            }
        }
        cout << s << '\n';
    }
    return 0;
}
