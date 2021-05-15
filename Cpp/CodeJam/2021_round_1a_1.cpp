#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i != t; ++i) {
        scanf("%d", &n);
        vector<long long> a(n);
        for (int j = 0; j != n; ++j) {
            scanf("%lld", &a[j]);
        }
        int ans = 0;
        for (int j = 1; j != n; ++j) {
            while (a[j] <= a[j - 1]) {
                a[j] = 10 * a[j] + 9;
                ++ans;
            }
        }
        printf("Case #%d: %d\n", i + 1, ans);
    }
    return 0;
}
