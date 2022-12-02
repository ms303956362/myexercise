#include <iostream>
#include <algorithm>
int a[100005];

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int min_diff = 0x3f3f3f3f;
    for (int i = 1; i < n; ++i) {
        min_diff = min(min_diff, a[i] - a[i - 1]);
    }
    cout << min_diff << endl;
    return 0;
}
