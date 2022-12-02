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
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    int cnt = 0, sum = 0;
    vector<int> idx;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            int t = cnt / b;
            if (t > 0) {
                sum += t;
                for (int j = i - b; t > 0; --t, j -= b) {
                    idx.push_back(j + 1);
                }
            }
            cnt = 0;
        } else {
            ++cnt;
        }
    }
    if (cnt / b > 0) {
        sum += cnt / b;
        for (int j = n - b, t = cnt / b; t > 0; --t, j -= b) {
            idx.push_back(j + 1);
        }
    }
    cout << sum - a + 1 << endl;
    for (int i = 0; i < (sum - a + 1); ++i) {
        cout << idx[i] << " ";
    }
    cout << endl;
    return 0;
}
