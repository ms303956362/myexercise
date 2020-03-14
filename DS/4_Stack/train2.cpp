#include <cstdio>
#include "Stack.h"
int *num;
char *progress;

bool permutation(int perm[], int n, int m) {
    Stack<int> s;
    int i = 0, j = 1, k = 0;
    while (j <= n) {
        if (s.size() <= m){
            if (i < n && perm[i] == j) {
                num[k] = perm[i++];
                progress[k++] = 'P';
                ++j;
            } else if (s.empty() || s.top() != j) { // 栈空或栈顶不是要找的元素
                if (i < n) {    // 初始栈未空
                    num[k] = perm[i];
                    s.push(perm[i++]);
                    progress[k++] = 'I';
                } else  // 初始栈空
                    return false;
            } else {
                num[k] = s.pop();
                progress[k++] = 'O';
                ++j;
            }
        } else {
            return false;
        }
    }
    progress[k] = '\0';
    return true;
}

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    progress = new char[2 * n + 1]; // 操作顺序
    int *perm = new int[n];
    num = new int[2 * n]; // 操作数字顺序
    for (int i = 0; i != n; ++i) {
        scanf("%d", perm + i);
    }
    bool ret = permutation(perm, n, m);
    if (ret) {
        for (int i = 0; progress[i] != '\0' ;++i){
            if (i == 0)
                printf("%d %c", num[i], progress[i]);
            else
                printf("\n%d %c", num[i], progress[i]);
        }
    } else {
        printf("No");
    }
    return 0;
}
