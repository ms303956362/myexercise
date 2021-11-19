#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int i, int max_num, int curr_sum, int curr_p, int sum, int &ans, vector<int>& cnt) {
    if (curr_sum + curr_p == sum) {
        ans = max(ans, curr_p);
        return;
    }
    if (i > max_num || curr_sum + curr_p > sum)
        return;
    while (i < max_num && cnt[i] == 0)
        ++i;
    dfs(i + 1, max_num, curr_sum, curr_p, sum, ans, cnt);
    for (int j = 0; j < cnt[i]; ++j) {
        curr_sum += i;
        curr_p *= i;
        dfs(i + 1, max_num, curr_sum, curr_p, sum, ans, cnt);
    }
    curr_sum -= i * cnt[i];
    curr_p /= i * cnt[i];
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int m;
        cin >> m;
        vector<int> cnt(500);
        int max_num = 0, sum = 0;
        for (int j = 0; j < m; ++j) {
            int num, c;
            cin >> num >> c;
            cnt[num] = c;
            sum += num * c;
            max_num = max(max_num, num);
        }
        int ans = 0;
        dfs(2, max_num, 0, 1, sum, ans, cnt);
        cout << "Case #" << t + 1 << ": " << ans << endl;
    }
}
