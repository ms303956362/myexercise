#include <iostream>
#include <unordered_map>

using ll = long long;
using namespace std;
int a[4005];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }
    unordered_map<int, ll> cnt;
    ll ans = 0;
    cnt[3 * a[n - 2] - a[n - 1]] = 1;
    for (int i = n - 3; i >= 0; --i) {
        ans += cnt[a[i]];
        for (int j = i + 1; j < n; ++j) {
            ++cnt[3 * a[i] - a[j]];
        }
    }
    cout << ans << endl;
    return 0;
}
