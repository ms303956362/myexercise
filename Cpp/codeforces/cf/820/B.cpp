// IO
#include <iostream>
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
    int q;
    cin >> q;
    while (q--) {
        int n;
        string t;
        cin >> n >> t;
        string s;
        int i = 0;
        while (i < n) {
            if (i + 2 < n && t[i + 2] == '0' && (i + 3 >= n || t[i + 3] != '0')) {
                s.push_back('a' + stoi(t.substr(i, 2)) - 1);
                i += 3;
            } else {
                s.push_back('a' + t[i] - '0' - 1);
                ++i;
            }
        }
        cout << s << endl;
    }
    return 0;
}
