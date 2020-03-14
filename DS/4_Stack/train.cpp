#include <cstdio>
#include "Stack.h"
char *progress;

bool permutation(int perm[], int n, int m) {
    Stack<int> s;
    int i = 0, j = 0, k = 0;
    while (i != n) {
        if (s.size() <= m){
            if (s.empty() || s.top() != perm[i]) { // 栈空或栈顶不是要找的元素
                if (j < n) {    // 初始栈未空
                    s.push(++j);
                    progress[k++] = 1;
                } else  // 初始栈空
                    return false;
            } else {
                s.pop();
                progress[k++] = 0;
                ++i;
            }
        } else {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n, m;
    Stack<int> a;
    scanf("%d %d", &n, &m);
    int *perm = new int[n];
    progress = new char[2 * n];
    for (int i = 0; i != n; ++i) {
        scanf("%d", perm + i);
    }
    bool ret = permutation(perm, n, m);
    if (ret) {
        for (int i = 0; i != 2 * n;++i)
            printf("%s\n", progress[i] == 1 ? "push" : "pop");
    } else {
        printf("No");
    }
    return 0;
}
