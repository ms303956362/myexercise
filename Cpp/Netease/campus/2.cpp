#include <iostream>
#include <algorithm>
using namespace std;

using ll = unsigned long long;

bool is_less_than(const pair<ll, ll>& num1, const pair<ll, ll>& num2) {
    return num1.first * num2.second < num1.second * num2.first;
}

int main(int argc, char const *argv[])
{
    ll x;
    cin >> x;
    pair<ll, ll> max_num{1, 1};
    for (ll n = 1; n <= x; ++n) {
        ll num = x / __gcd(x, n), den = n / __gcd(x, n);
        ll prod_num = 1, prod_den = 1;
        for (unsigned int i = 0; i < n; ++i) {
            prod_num *= num;
            prod_den *= den;
        }
        ll g = __gcd(prod_den, prod_num);
        auto prod = make_pair(prod_num / g, prod_den / g);
        if (is_less_than(max_num, prod)) {
            max_num = prod;
        }
    }
    cout << max_num.first << " " << max_num.second << endl;
    return 0;
}
