#include <iostream>
#include <string>
#include <stack>
using namespace std;

using ll = long long;

int level[256];

ll mod = 10007;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    level['+'] = 1;
    level['*'] = 2;
    level['('] = 0;
    stack<pair<ll, ll>> sn;
    stack<char> sc;
    auto calc = [&]() {
        auto [c0, c1] = sn.top();
        sn.pop();
        auto [a0, a1] = sn.top();
        sn.pop();
        ll t0 = 1, t1 = 1;
        if (sc.top() == '*') {
            t0 = (c0 * a0 % mod + c0 * a1 % mod + c1 * a0 % mod) % mod;
            t1 = c1 * a1 % mod;
        } else if (sc.top() == '+') {
            t0 = c0 * a0 % mod;
            t1 = (c0 * a1 % mod + c1 * a0 % mod + c1 * a1 % mod) % mod;
        }
        sn.emplace(t0, t1);
        sc.pop();
    };
    for (int i = 0; i < n; ++i) {
        if (s[i] == '+') {
            if (!sc.empty() && level[s[i]] <= level[sc.top()]) {
                if (s[i - 1] != ')') {
                    sn.emplace(1, 1);
                }
                calc();
            } else {
                sn.emplace(1, 1);
            }
            sc.push(s[i]);
        } else if (s[i] == '*') {
            if (!sc.empty() && level[s[i]] <= level[sc.top()]) {
                if (s[i - 1] != ')') {
                    sn.emplace(1, 1);
                }
                calc();
            } else {
                sn.emplace(1, 1);
            }
            sc.push(s[i]);
        } else if (s[i] == '(') {
            sc.push(s[i]);
        } else {
            ll c0 = 1, c1 = 1;
            while (sc.top() != '(') {
                auto [a0, a1] = sn.top();
                sn.pop();
                if (sc.top() == '+') {
                    ll t0 = c0 * a0 % mod;
                    ll t1 = (c0 * a1 % mod + c1 * a0 % mod + c1 * a1 % mod) % mod;
                    c0 = t0;
                    c1 = t1;
                } else {
                    ll t0 = (c0 * a0 % mod + c0 * a1 % mod + c1 * a0 % mod) % mod;
                    ll t1 = c1 * a1 % mod;
                    c0 = t0;
                    c1 = t1;
                }
                sc.pop();
            }
            sc.pop();
            sn.emplace(c0, c1);
        }
    }
    ll c0 = 1, c1 = 1;
    if (sn.size() > sc.size()) {
        auto [t0, t1] = sn.top();
        sn.pop();
        c0 = t0;
        c1 = t1;
    }
    while (!sc.empty()) {
        auto [a0, a1] = sn.top();
        sn.pop();
        if (sc.top() == '+') {
            ll t0 = c0 * a0 % mod;
            ll t1 = (c0 * a1 % mod + c1 * a0 % mod + c1 * a1 % mod) % mod;
            c0 = t0;
            c1 = t1;
        } else {
            ll t0 = (c0 * a0 % mod + c0 * a1 % mod + c1 * a0 % mod) % mod;
            ll t1 = c1 * a1 % mod;
            c0 = t0;
            c1 = t1;
        }
        sc.pop();
    }
    cout << c0 << endl;
    return 0;
}
