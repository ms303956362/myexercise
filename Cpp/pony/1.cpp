#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

using ll = long long;

ll a[100005];

int main(int argc, char const *argv[])
{
    ll n, k;
    cin >> n >> k;
    --k;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    set<ll> st(a, a + n);
    // for (const auto& p : cnt) {
    //     st.insert(p.second);
    // }
    ll m = n, min_num = *st.begin();
    ll total = 0;
    while ((min_num - total) * m <= k) {
        k -= (min_num - total)  * m;
        m -= cnt[min_num];
        st.erase(st.begin());
        total = min_num;
        min_num = *st.begin();
    }
    k %= m;
    ll c = 0;
    int i = 0;
    for (; i < n && c <= k; ++i) {
        if (a[i] >= min_num) {
            ++c;
        }
        if (c > k) {
            break;
        }
    }
    cout << i + 1 << endl;
    return 0;
}
