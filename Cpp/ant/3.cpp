#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    unordered_map<int, ll> cnt;
    cnt[0] = 1;
    int state = 0;
    for (int i = n - 1; i >= 0; --i) {
        state ^= (1 << (s[i] - 'a'));
        for (int k = 0; k < 26; ++k) {
            int tmp = state ^ (1 << k);
            ans += cnt[tmp];
        }
        ++cnt[state];
    }
    cout << ans << endl;
    return 0;
}
