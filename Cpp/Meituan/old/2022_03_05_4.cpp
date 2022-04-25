#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> add(n + 1), cnt(n + 1);
    long long bonus = 0;
    for (int i = 0; i < m; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            for (int j = l; j <= r; ++j) {
                ++cnt[j];
                bonus += add[j];
            }
        } else {
            int l, r;
            long long k;
            cin >> l >> r >> k;
            for (int j = l; j <= r; ++j) {
                add[j] += k;
            }
        }
    }
    sort(cnt.begin(), cnt.end());
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += cnt[i] * a[i - 1];
    }
    cout << ans + bonus << endl;
    return 0;
}
