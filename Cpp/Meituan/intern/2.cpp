#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n), cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        cnt[i] = cnt[i + 1] + (a[i] == -1);
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n; j > i; --j) {
            if ((cnt[i] - cnt[j]) % 2 == 0) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
