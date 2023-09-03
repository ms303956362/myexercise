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
    vector<vector<char>> a(h, vector<char>(w)), b(h, vector<char>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> b[i][j];
        }
    }
    auto check = [&]() {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (a == b) {
                    return true;
                }
                vector<int> tmp;
                for (int k = 0; k < h; ++k) {
                    tmp.push_back(a[k][0]);
                }
                for (int k = 0; k < w - 1; ++k) {
                    for (int l = 0; l < h; ++l) {
                        a[l][k] = a[l][k + 1];
                    }
                }
                for (int l = 0; l < h; ++l) {
                    a[l][w - 1] = tmp[l];
                }
            }
            auto a0 = a[0];
            a.erase(a.begin());
            a.push_back(a0);
        }
        return false;
    };
    if (check()) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    return 0;
}
