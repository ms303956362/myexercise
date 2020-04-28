#include <cstdio>
#include <cstring>

char ht[1200007][41];
int idx[1200007];
unsigned long long M = 1200007;

static size_t hashCode(char* s) {
    size_t h = 0;
    int n = strlen(s);
    for (int i = 0; i != n; ++i) {
        h = (h << 5) | (h >> 59); // 循环左移5位
        h += static_cast<size_t>(s[i]);
    }
    return h;
}

size_t probe(char* k) { // 找匹配
    size_t c = hashCode(k) % M, r = c;
    size_t i = 1;
    while (idx[r] && strcmp(ht[r], k)) {
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
    char s[41];
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        scanf("%s", s);
        int r = probe(s);
        if (idx[r] == 1) {
            idx[r] = 2; // idx[r] == 2 <=> ht[r]已重复，不再接受访问
            printf("%s\n", s);
        }
        else if (idx[r] == 0){  // idx[r] == 0 <=> ht[r]为空
            strcpy(ht[r], s);
            idx[r] = 1;  // idx[r] == 1 <=> ht[r]只出现1次
        }
    }
    return 0;
}
