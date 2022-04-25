#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int n = s.size(), i = 0;
    bool first1 = (s[0] == '1');
    ll mod = 1e9 + 7;
    vector<ll> cnt;
    while (i < n) {
        int j = i + 1;
        while (j < n && s[j] == s[i]) {
            ++j;
        }
        cnt.push_back(j - i);
        i = j;
    }
    n = cnt.size();
    if (s[0] == '0') {
        ++cnt[0];
    }
    if (n > 1 && s.back() == '0') {
        ++cnt[n - 1];
    }
    vector<ll> pre(n, 1), post(n, 1);
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] * cnt[i - 1] % mod;
    }
    for (int i = n - 2; i >= 0; --i) {
        post[i] = post[i + 1] * cnt[i + 1] % mod;
    }
    ll ans = pre[n - 1] * cnt[n - 1] % mod;
    i = (first1 ? 0 : 1);
    while (i < n) {
        int j = i - 2;
        ll sum = cnt[i];
        while (j >= 0) {
            sum = (sum + cnt[j]) % mod;
            ans = (ans + pre[j] * post[i] * sum % mod) % mod;
            j -= 2;
        }
        i += 2;
    }
    cout << ans % mod << endl;
    return 0;
}
