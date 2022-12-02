#include <iostream>

using namespace std;
using ll = long long;

ll pow(ll a, ll b, ll mod) {
    ll res = 1, p = a % mod;
    while (b > 0) {
        if (b & 1) {
            res = (res * p) % mod;
        }
        p = (p * p) % mod;
        b >>= 1;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ll a = 5;
    cout << a << endl;
    cout << pow(a, a, 10) << endl;
    return 0;
}
