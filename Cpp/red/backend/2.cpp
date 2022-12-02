#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll i = 0, j = n - 1;
    ll ans = 0;
    while (i < n) {
        while (j >= 0 && a[i] * a[j] >= k) {
            --j;
        }
        ans += n - 1 - j;
        if (j < i) {
            --ans;
        }
        ++i;
    }
    cout << ans << endl;
    return 0;
}
