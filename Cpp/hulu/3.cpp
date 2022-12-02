#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k, t;
    cin >> n >> k >> t;
    vector<vector<int>> s(n, vector<int>(k)), p(n, vector<int>(k));
    long long total_s = 0, total_p = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> s[i][j];
            total_s += s[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> p[i][j];
            total_p += p[i][j];
        }
    }
    // if (total_s >= t) {
    //     cout << total_p << endl;
    //     return 0;
    // }
    vector<int> sum(n, 0);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = 0;
        long long total = 0, pm = 0;
        while (j < k && total + s[i][j] <= t) {
            total += s[i][j];
            pm += p[i][j];
        }
        ans = max(ans, pm);
    }
    cout << ans << endl;
    return 0;
}
