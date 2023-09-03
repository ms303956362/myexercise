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
    map<int, multiset<int>> box2card;
    map<int, set<int>> card2box;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, j;
            cin >> i >> j;
            card2box[i].insert(j);
            box2card[j].insert(i);
        } else if (op == 2) {
            int i;
            cin >> i;
            for (const auto& card : box2card[i]) {
                cout << card << ' ';
            }
            cout << '\n';
        } else {
            int i;
            cin >> i;
            for (const auto& box : card2box[i]) {
                cout << box << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
