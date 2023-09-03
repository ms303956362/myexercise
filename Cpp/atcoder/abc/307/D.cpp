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
#include <numeric>
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    stack<char> st;
    for (int i = 0; i < n; ++i) {
        if (s[i] == ')') {
            if (cnt > 0) {
                while (!st.empty() && st.top() != '(') {
                    st.pop();
                }
                st.pop();
                --cnt;
            } else {
                st.push(')');
            }
        } else if (s[i] == '(') {
            ++cnt;
            st.push('(');
        } else {
            st.push(s[i]);
        }
    }
    string ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}
