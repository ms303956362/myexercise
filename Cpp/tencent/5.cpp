#include <iostream>
using namespace std;

bool dp1[105][100005], dp2[105][100005];
int a[105];
bool isX[105];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    dp1[n][0] = true;
    dp2[n][0] = true;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= sum; ++j) {
            dp1[i][j] = dp1[i + 1][j];
            if (j >= a[i]) {
                dp1[i][j] |= dp1[i + 1][j - a[i]];
                dp2[i][j] = dp1[i + 1][j - a[i]];
            }
        }
    }
    int min_diff = sum, min_sum = 0;
    for (int s = 0; s <= sum; ++s) {
        if (dp1[0][s] && abs(abs(sum - s) - abs(s)) < min_diff) {
            min_diff = abs(abs(sum - s) - abs(s));
            min_sum = s;
        }
    }
    int i = 0, s = sum - min_sum;
    while (i < n && s > 0) {
        while (i < n && !dp2[i][s]) {
            ++i;
        }
        isX[i] = true;
        s -= a[i];
    }
    cout << min_sum << " " << min_sum - sum << endl;
    for (int i = 0; i < n; ++i) {
        cout << (isX[i] ? 'X' : 'Y');
    }
    cout << endl;
    return 0;
}
