#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    int n;
    scanf("%d", &n);
    int* selected = new int[n + 1], *a = new int [n], *b = new int [n], *c = new int [n];
    char name[3] = {'A', 'B', 'C'};
    memset(selected, 0, (n + 1) * (sizeof(int)));
    for (int i = 0; i != n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i != n; ++i) {
        scanf("%d", b + i);
    }
    for (int i = 0; i != n; ++i) {
        scanf("%d", c + i);
    }
    int q = 0;
    scanf("%d", &q);
    // start
    int j = 0, k = 0, m = 0;
    int answer = -1;
    for (int i = 0; i != n; ++i) {
        if (i % 3 == 0) {
            while (selected[a[j]]) 
                ++j;
            selected[a[j]] = 1;
            if (q == a[j]) 
                answer = 0;
        } else if (i % 3 == 1) {
            while (selected[b[k]]) 
                ++k;
            selected[b[k]] = 1;
            if (q == b[k]) 
                answer = 1;
        } else {
            while (selected[c[m]]) 
                ++m;
            selected[c[m]] = 1;
            if (q == c[m]) 
                answer = 2;
        }
        if (answer != -1)
            break;
    }
    // end
    printf("%c", name[answer]);
    return 0;
}
