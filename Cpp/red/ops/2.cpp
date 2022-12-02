#include <iostream>

using namespace std;
using ll = long long;
ll a[30005];
ll left_cnt[30005][2], right_cnt[30005][2];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    left_cnt[0][1] = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i < n; ++i) {
        left_cnt[i][0] = min(left_cnt[i - 1][0] + abs(a[i - 1] - 1), left_cnt[i - 1][1] + abs(a[i - 1] + 1));
        left_cnt[i][1] = min(left_cnt[i - 1][0] + abs(a[i - 1] + 1), left_cnt[i - 1][1] + abs(a[i - 1] - 1));
    }
    right_cnt[n - 1][1] = 0x3f3f3f3f3f3f3f3f;
    for (int i = n - 2; i >= 0; --i) {
        right_cnt[i][0] = min(right_cnt[i + 1][0] + abs(a[i + 1] - 1), right_cnt[i + 1][1] + abs(abs(a[i + 1] + 1)));
        right_cnt[i][1] = min(right_cnt[i + 1][0] + abs(a[i + 1] + 1), right_cnt[i + 1][1] + abs(abs(a[i + 1] - 1)));
    }
    ll ans = min(abs(a[0] + 7) + right_cnt[0][1], abs(a[0] - 7) + right_cnt[0][0]);
    ans = min(ans, min(abs(a[n - 1] + 7) + left_cnt[n - 1][1], abs(a[n - 1] - 7) + left_cnt[n - 1][0]));
    for (int i = 1; i < n - 2; ++i) {
        ans = min(ans,
            min(
                abs(a[i] - 7) + min(left_cnt[i][0] + right_cnt[i][0], left_cnt[i][1] + right_cnt[i][1]),
                abs(a[i] + 7) + min(left_cnt[i][1] + right_cnt[i][0], left_cnt[i][0] + right_cnt[i][1])
            )
        );
    }
    cout << ans << endl;
    return 0;
}
