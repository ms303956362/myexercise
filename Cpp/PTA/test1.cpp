#include <cstdio>

int main() {
    int n = 0;
    char c;
    scanf("%d %c", &n, &c);
    int num = 1, sum = 1;
    while (sum <= n) {
        num += 2;
        sum += 2 * num;
    }
    sum -= 2 * num;
    num -= 2;
    for (int i = num; i > 1; i -= 2) {
        for (int j = (num - i) / 2; j > 0; --j) {
            printf(" ");
        }
        for (int j = 0; j < i; ++j) {
            printf("%c", c);
        }
        printf("\n");
    }
    for (int j = (num - 1) / 2; j > 0; --j) {
        printf(" ");
    }
    printf("%c\n", c);
    for (int i = 3; i <= num; i += 2) {
        for (int j = (num - i) / 2; j > 0; --j) {
            printf(" ");
        }
        for (int j = 0; j < i; ++j) {
            printf("%c", c);
        }
        printf("\n");
    }
    printf("%d", n - sum);
    return 0;
}
