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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x % 2 == 0) {
                ++cnt0;
            } else {
                ++cnt1;
            }
        }
        if (cnt1 % 2 == 0) {
            if ((cnt1 / 2) % 2 == 0) {
                cout << "Alice" << endl;
            } else {
                cout << "Bob" << endl;
            }
        } else {
            if (cnt0 % 2 == 0) {
                if (((cnt1 - 1) / 2) % 2 == 1) {
                    cout << "Alice" << endl;
                } else {
                    cout << "Bob" << endl;
                }
            } else {
                cout << "Alice" << endl;
            }
        }
    }
    return 0;
}
