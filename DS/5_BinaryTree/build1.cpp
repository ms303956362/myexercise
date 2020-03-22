#include <cstdio>
#include <cstring>
#include "List.h"
#include "Queue.h"

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);

    int n;
    scanf("%d", &n);
    // 父亲孩子表示法
    int *p = new int[n + 1];
    memset(p, 0, (n + 1) * sizeof(int));
    List<int> *c = new List<int>[n + 1];
    // 构建树
    int n_c, node;
    for (int i = 1; i != n + 1; ++i) {
        scanf("%d", &n_c);
        for (int j = 0; j != n_c; ++j) {
            scanf("%d", &node);
            c[i].insertAsLast(node);
            p[node] = i;
        }
    }
    // 层次遍历
    Queue<int>* q = new Queue<int>;
    q->enqueue(1);
    int nd;
    while (!q->empty()) {
        nd = q->dequeue();
        printf("%d\n", nd);
        for (Posi<int> pn = c[nd].first(); pn != c[nd].last()->succ; pn = pn->succ) {
            q->enqueue(pn->data);
        }
    }
    return 0;
}
