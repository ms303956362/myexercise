#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> dishes(n);
    for (int i = 0; i < n; ++i) {
        cin >> dishes[i].first >> dishes[i].second;
    }
    int ans = 0;
    for (int s = 0; s < (1 << n); ++s) {
        vector<int> cnt(m + 1);
        bool ok = true;
        int len = 0;
        for (int i = 0; i < n; ++i) {
            if (s & (1 << i)) {
                ++len;
                if (cnt[dishes[i].first] > 0 || cnt[dishes[i].second] > 0) {
                    ok = false;
                    break;
                }
                ++cnt[dishes[i].first];
                ++cnt[dishes[i].second];
            }
        }
        if (ok) {
            ans = max(ans, len);
        }
    }
    cout << ans << endl;
    return 0;
}
