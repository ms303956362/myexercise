#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    priority_queue<pair<ll, ll>> q;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        q.emplace(x - __builtin_popcount(x), x);
        sum += x;
    }
    for (int i = 0; i < k; ++i) {
        auto [diff, x] = q.top();
        q.pop();
        sum -= diff;
        x = __builtin_popcount(x);
        q.emplace(x - __builtin_popcount(x), __builtin_popcount(x));
    }
    cout << sum << endl;
    return 0;
}
