#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solve(vector<int>& a) {
    int n = a.size();
    int max_cnt = 0;
    unordered_map<int, int> cnt, left, right;
    for (int i = 0; i < n; ++i) {
        ++cnt[a[i]];
        max_cnt = max(max_cnt, cnt[a[i]]);
        if (!left.count(a[i])) {
            left[a[i]] = i;
        }
        right[a[i]] = i;
    }
    int ans = n;
    for (const auto& [i, f] : cnt) {
        if (f == max_cnt) {
            ans = min(ans, right[i] - left[i] + 1);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> a{1, 2, 2, 3, 1};
    cout << solve(a) << endl;
    return 0;
}
