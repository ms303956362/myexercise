#include <iostream>
#include <vector>
#include <map>
#include <utility>
using  namespace std;


int main(int argc, char const *argv[])
{
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> l(n), r(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    map<int, pair<int, int>> diff;
    for (int i = 0; i < n; ++i) {
        if (t[i] == 1) {
            ++diff[l[i]].first;
            --diff[r[i] + 1].first;
        } else {
            ++diff[l[i]].second;
            --diff[r[i] + 1].second;
        }
    }
    int last = -1, op1 = 0, op2 = 0, ans = 0;
    for (const auto& pp : diff) {
        int x = pp.first;
        if (op1 >= p && op2 >= q) {
            ans += x - last;
        }
        op1 += pp.second.first;
        op2 += pp.second.second;
        last = x;
    }
    cout << ans << endl;
    return 0;
}
