#include <iostream>

using namespace std;

int a[100005], b[100005], diff1[100005], diff2[100005];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        diff1[i] = a[i + 1] - a[i];
        diff2[i] = b[i + 1] - b[i];
    }
    int ans = 1, max_len = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (diff1[i] == diff2[i]) {
            ++max_len;
        } else {
            max_len = 0;
        }
        ans = max(ans, max_len + 1);
    }
    cout << ans << endl;
    return 0;
}
