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
    unordered_set<string> st;
    unordered_set<char> st1{ 'H', 'D', 'C', 'S'}, st2{'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (!st1.count(s[0]) || !st2.count(s[1]) || st.count(s)) {
            ok = false;
        }
        st.insert(s);
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
