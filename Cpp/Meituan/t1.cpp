#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];

int main(int argc, char const *argv[])
{
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int time = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (time + t <= a[i]) {
            time += t;
        } else {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
