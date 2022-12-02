#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
int a[400005];

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    unordered_map<int, int> cnt_even, cnt_odd;
    for (int i = 0; i < n; ++i) {
        if (i % 2) {
            ++cnt_odd[a[i]];
        } else {
            ++cnt_even[a[i]];
        }
    }
    vector<pair<int, int>> cnt_odd_vp, cnt_even_vp;
    for (const auto& [num, c] : cnt_even) {
        cnt_even_vp.emplace_back(c, num);
    }
    for (const auto& [num, c] : cnt_odd) {
        cnt_odd_vp.emplace_back(c, num);
    }
    cnt_even_vp.emplace_back(0, 0);
    cnt_odd_vp.emplace_back(0, 0);
    sort(cnt_even_vp.rbegin(), cnt_even_vp.rend());
    sort(cnt_odd_vp.rbegin(), cnt_odd_vp.rend());
    if (cnt_even_vp[0].second != cnt_odd_vp[0].second) {
        cout << n - cnt_even_vp[0].first - cnt_odd_vp[0].first << endl;
    } else {
        cout << n - max(cnt_even_vp[1].first + cnt_odd_vp[0].first, cnt_even_vp[0].first + cnt_odd_vp[1].first) << endl;
    }
    return 0;
}
