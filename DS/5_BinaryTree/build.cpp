#include <cstdio>
#include <cstring>
#include "List.h"
#include "Queue.h"

Posi<int> getNode(int *p, List<int> *c) {
    int depth, r, node = 1;
    Posi<int> ptr = c[0].first();
    scanf("%d", &depth);
    int j = 0;
    for (j = 0; j != depth; ++j) {
        scanf("%d", &r);
        if (r >= c[node].size())
            break;
        ptr = c[node].first();
        for (int k = 0; k != r; ++k)
            ptr = ptr->succ;
        node = ptr->data;
    }
    while (++j < depth)
        scanf("%d", &r);
    return ptr;
}

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);

    int n, m;
    scanf("%d %d", &n, &m);
    // 父亲孩子表示法
    int *p = new int[n + 1];
    memset(p, 0, (n + 1) * sizeof(int));
    List<int> *c = new List<int>[n + 1];
    // 构建树
    c[0].insertAsLast(1);
    int n_c, node;
    for (int i = 1; i != n + 1; ++i) {
        scanf("%d", &n_c);
        for (int j = 0; j != n_c; ++j) {
            scanf("%d", &node);
            c[i].insertAsLast(node);
            p[node] = i;
        }
    }
    // 移动
    int src, dst, r;
    Posi<int> p_src, p_dst;
    for (int i = 0; i != m; ++i) {
        // 源节点
        p_src = getNode(p, c);
        src = p_src->data;
        c[p[src]].remove(p_src);    //先移除节点
        // 目标节点
        dst = getNode(p, c)->data;
        scanf("%d", &r);
        // 移动
        p[src] = dst;
        p_dst = c[dst].first();
        for (int j = 0; j != r; ++j)
             p_dst =  p_dst->succ;
        c[dst].insertB(p_dst, src);
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
