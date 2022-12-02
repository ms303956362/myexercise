#include <iostream>

using namespace std;

int a[105];

int main(int argc, char const *argv[])
{
    long long n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    --k;
    k %= (2 * n);
    if (k < n) {
        cout << a[k] << endl;
    } else {
        cout << a[2 * n - 1 - k] << endl;
    }
    return 0;
}
