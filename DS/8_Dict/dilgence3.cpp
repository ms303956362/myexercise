#include <cstdio>
#include <cstring>

char ht[20011][9];
int cnt[20011];
int M = 20011;

static long long hashCode(char* s) {
    long long h = 0;
    int n = strlen(s);
    for (int i = 0; i != n; ++i) {
        h = (h << 5) | (h >> 59); // 循环左移5位
        h += static_cast<long long>(s[i]);
    }
    return h;
}

int probe(char* k) { // 找匹配
    long long c = hashCode(k) % M, r = c;
    int i = 1;
    while (cnt[r] && strcmp(ht[r], k)) {
        r = (c + i * i) % M;
        ++i;
    }
    return r;
}

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    int n;
    char s[10];
    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%s", s);
        int r = probe(s);
        if (cnt[r])
            ++cnt[r];
        else {
            strcpy(ht[r], s);
            cnt[r] = 1;
        }
    }
    int max_cnt = 0;
    for (int i = 0; i != M; ++i) {
        if (cnt[i] > max_cnt) {
            strcpy(s, ht[i]);
            max_cnt = cnt[i];
        }
    }
    printf("%s %d", s, max_cnt);
    return 0;
}
