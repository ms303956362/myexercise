#include <iostream>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;
ll dp0[1000005], dp1[1000005], pow26[1000005];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    pow26[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pow26[i] = (pow26[i - 1] * 26) % mod;
    } 
    dp1[3] = 1;
    dp1[4] = 26 + 26;
    for (int i = 5; i <= n; ++i) {
        dp1[i] = (3 * pow26[i - 3] + 26 * (dp1[i - 3] - dp1[i - 4]) + 26 * 26 * (dp1[i - 3] - dp1[i - 5]) + (26 * 26 * 26 - 1 - 26 - 26 * 26) * dp1[i - 3] % mod) % mod;
    }
    for (int i = 6; i <= n; ++i) {
        dp0[i] = (dp1[i - 3] + 26 * dp1[i - 4] % mod + 26 * 26 * dp1[i - 5] % mod + (26 * 26 * 26 - 1 - 26 - 26 * 26) * dp0[i - 3]) % mod;
    }
    cout << dp0[n] << endl;
    return 0;
}
