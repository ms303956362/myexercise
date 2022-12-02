#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

ll cnt(ll n) {
    ll mask = 1;
    int i = 0;
    vector<ll> c(64);
    for (; i < 60; ++i) {
        c[i] = mask / 2;
        mask *= 2;
    }
    c[0] = 1;
    i = 60;
    ll ans = 0, rev = 0;
    while (mask > 1) {
        if (mask & n) {
            ans += c[i];
            rev ^= 1;
        }
        mask /= 2;
        --i;
    }
    if ((n & 1) == 1 && !rev) {
        ++ans;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ll l, r;
    cin >> l >> r;
    cout << cnt(r) - cnt(l - 1) << endl;
    return 0;
}
