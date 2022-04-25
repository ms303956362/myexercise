#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll pre = a[0], min_pre = min((ll)0, a[0]);
    vector<ll> max_sum(n);
    max_sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pre += a[i];
        max_sum[i] = max(max_sum[i - 1], pre - min_pre);
        min_pre = min(min_pre, pre);
    }
    long long post = a[n - 1], min_post = min((ll)0, a[n - 1]);
    vector<long long> max_sum2(n);
    max_sum2[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        post += a[i];
        max_sum2[i] = max(max_sum2[i + 1], post - min_post);
        min_post = min(min_post, post);
    }
    long long ans = max(max_sum[n - 1], max_sum2[0]);
    for (int i = 1; i < n; ++i) {
        ans = max({ans, max_sum[i - 1], max_sum2[i], max_sum[i - 1] + max_sum2[i]});
    }
    cout << ans << endl;
    return 0;
}
