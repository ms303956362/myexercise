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
    int h, w;
    cin >> h >> w;
    vector<string> s, t;
    for (int i = 0; i < h; ++i) {
        string tmp;
        cin >> tmp;
        s.push_back(tmp);
    }
    for (int i = 0; i < h; ++i) {
        string tmp;
        cin >> tmp;
        t.push_back(tmp);
    }
    map<string, int> cnts, cntt;
    for (int j = 0; j < w; ++j) {
        string c;
        for (int i = 0; i < h; ++i) {
            c.push_back(s[i][j]);
        }
        ++cnts[c];
    }
    for (int j = 0; j < w; ++j) {
        string c;
        for (int i = 0; i < h; ++i) {
            c.push_back(t[i][j]);
        }
        ++cntt[c];
    }
    if (cnts == cntt) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
