#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<ll> a(n), pre_pos(n), pre_neg(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = n - 1; i >= 0; --i) {
        pre_neg[i] = pre_neg[i + 1] - a[i];
        pre_pos[i] = pre_pos[i + 1] + a[i];
    }
    int m;
    cin >> m;
    ll x = 0;
    for (int i = 0; i < m; ++i) {
        ll num;
        cin >> num;
        x += num;
        int k = lower_bound(a.begin(), a.end(), -x) - a.begin();
        cout << -x * k + x * (n - k) + pre_neg[0] - pre_neg[k] + pre_pos[k] - pre_pos[n] << endl;
    }
    return 0;
}
