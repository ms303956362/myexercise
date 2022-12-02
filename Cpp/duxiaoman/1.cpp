#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
ll a[1005];

int main(int argc, char const *argv[])
{
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        long long max_num = 0xff3f3f3fff3f3f3f, min_num = 0x3f3f3f3f3f3f3f3f;
        for (int j = i; j < n; ++j) {
            max_num = max(max_num, a[j]);
            min_num = min(min_num, a[j]);
            if (min_num * k == max_num) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
