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
        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<int> st;
        int cnt = 0, ans = 0;
        for (int i = 0; i < 2 * n; ++i) {
            if (s[i] == '(') {
                ++cnt;
            } else {
                --cnt;
                while (!st.empty() && cnt < st.top()) {
                    st.pop();
                }
                if (st.empty() || cnt > st.top()) {
                    st.push(cnt);
                    ++ans;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
