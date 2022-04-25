#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    vector<int> a(5);
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    // cout << min(a[0] + a[1], a[2]) << endl;
    int ans = 0;
    while (a[0] > 0 || a[1] > 0) {
        for (int i = 1; i < 5; ++i) {
            --a[i];
        }
        sort(a.begin(), a.end());
        ++ans;
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
    }
    return 0;
}
