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

void print(vector<int>& a) {
    for (const auto& num : a) {
        cout << num << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        if (n == 4) {
            a = vector<int>{2, 1, 3, 4};
        } else if (n == 5) {
            a = vector<int>{1, 2, 3, 4, 5};
        } else {
            a[n - 1] = n;
            a[n - 2] = n - 3;
            a[n - 3] = 2;
            a[n - 4] = 1;
            a[0] = n - 2;
            a[1] = n - 1;
            if (n % 2) {
                swap(a[0], a[1]);
            }
            for (int i = 2, j = n - 5; i < n - 4; ++i, --j) {
                a[j] = i + 1;
            }
        }
        print(a);
    }
    return 0;
}
