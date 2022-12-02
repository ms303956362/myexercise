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
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (m < n) {
            cout << "No" << endl;
        } else {
            if (n % 2 == 1) {
                cout << "Yes" << endl;
                for (int i = 0; i < n - 1; ++i) {
                    cout << 1 << " ";
                }
                cout << m - n + 1 << endl;
            } else {
                if (m % 2 == 0) {
                    cout << "Yes" << endl;
                    for (int i = 0; i < n - 2; ++i) {
                        cout << 1 << " ";
                    }
                    cout << (m - n + 2) / 2 << " " << (m - n + 2) / 2 << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }
    }
    return 0;
}
