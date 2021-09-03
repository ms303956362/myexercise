#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    vector<bool> isprime(n + 1, true);
    for (int i = 2; i <= sqrt(n) + 1; ++i) {
        if (!isprime[i])
            continue;
        for (int j = i; j * i <= n; ++j)
            isprime[j * i] = false;
    }
    int prev = 2, ans = 0;
    for (int i = 3; i <= n; ++i) {
        if (isprime[i]) {
            if (i - prev == 2)
                ++ans;
            prev = i;
        }
    }
    printf("%d", ans);
    return 0;
}
