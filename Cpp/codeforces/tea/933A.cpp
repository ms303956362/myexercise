#include <iostream>
#include <vector>
using namespace std;

int a[2005];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    vector<int> pre1(n + 1), pre2(n + 1), left_max(n), right_max(n);
    for (int i = n - 1; i >= 0; --i) {
        pre1[i] = pre1[i + 1];
        pre2[i] = pre2[i + 1];
        if (a[i] == 1) {
            ++pre1[i];
        } else {
            ++pre2[i];
        }
    }
    left_max[0] = pre2[0] - pre1[0];
    for (int i = 1; i < n; ++i) {
        left_max[i] = max(left_max[i - 1], pre2[i] - pre1[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        right_max[i] = max(right_max[i + 1], pre2[i + 1] - pre1[i + 1]);
    }
    int ans = max(pre1[0], pre2[0]);
    for (int i = 0; i < n; ++i) {
        ans = max(ans, pre1[0] + left_max[i] + right_max[i] + pre1[i] - pre2[i]);
    }
    cout << ans << endl;
    return 0;
}
