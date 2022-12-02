#include <iostream>

#include <vector>
#include <list>
#include <string>

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s.insert(a[i]);
    }
    vector<int> b(s.begin(), s.end());
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    int max_cnt = 0;
    unordered_set<int> st;
    for (int i = 0; i < n; ++i) {
        if (st.count(a[i] - 1) && st.count(a[i]) && st.count(a[i] + 1)) {
            continue;
        }
        ++max_cnt;
        if (!st.count(a[i] - 1)) {
            st.insert(a[i] - 1);
        } else if (!st.count(a[i])) {
            st.insert(a[i]);
        } else {
            st.insert(a[i] + 1);
        }
    }
    int min_cnt = 0, m = b.size();
    for (int i = 0; i < m; ++i) {
        ++min_cnt;
        if (i + 1 < m && b[i + 1] == b[i] + 1) {
            ++i;
            if (i + 1 < m && b[i + 1] == b[i] + 1) {
                ++i;
            }
        } else if (i + 1 < m && b[i + 1] == b[i] + 2) {
            ++i;
        }
    }
    cout << min_cnt << " " << max_cnt << endl;
    return 0;
}
