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
    string s;
    cin >> s;
    int i = 0, j = s.size() - 1;
    string ans;
    while (j - i >= 3) {
        if (s[i] == s[j] || s[i] == s[j - 1]) {
            ans.push_back(s[i]);
        } else {
            ans.push_back(s[i + 1]);
        }
        i += 2;
        j -= 2;
    }
    int k = ans.size() - 1;
    if (i <= j) {
        ans.push_back(s[(i + j) / 2]);
    }
    while (k >= 0) {
        ans.push_back(ans[k]);
        --k;
    }
    cout << ans << endl;
    return 0;
}
