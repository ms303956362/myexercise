#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    m %= n;
    vector<int> a(n);
    int num;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        a[i] = num;
    }
    int start = 0, cnt = 0;
    while (cnt < n) {
        int nxt = (start + m) % n, tmp1 = a[start], tmp2 = a[nxt];
        while (nxt != start) {
            tmp2 = a[nxt];
            a[nxt] = tmp1;
            tmp1 = tmp2;
            nxt = (nxt + m) % n;
            ++cnt;
        }
        a[nxt] = tmp1;
        ++cnt;
        ++start;
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0)
            printf(" ");
        printf("%d", a[i]);
    }
    return 0;
}
