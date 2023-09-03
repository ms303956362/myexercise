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
    string s, t;
    cin >> s >> t;
    unordered_set<char> st{'a', 't', 'c', 'o', 'd', 'e', 'r'};
    vector<int> cnts(26), cntt(26);
    int cs = 0, ct = 0;
    for (const auto& c : s) {
        if (c != '@') {
            ++cnts[c - 'a'];
        } else {
            ++cs;
        }
    }
    for (const auto& c : t) {
        if (c != '@') {
            ++cntt[c - 'a'];
        } else {
            ++ct;
        }
    }
    int needs = 0, needt = 0;
    for (int i = 0; i < 26; ++i) {
        if (!st.count(i + 'a')) {
            if (cnts[i] != cntt[i]) {
                cout << "No" << '\n';
                return 0;
            }
        } else {
            if (cnts[i] > cntt[i]) {
                needt += cnts[i] - cntt[i];
            } else {
                needs += cntt[i] - cnts[i];
            }
        }
    }
    cout << ((needs <= cs && needt <= ct) ? "Yes" : "No") << '\n';
    return 0;
}
