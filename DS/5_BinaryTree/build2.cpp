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

int getHeight(int *ht, List<int> *c, int node) {
    if (c[node].size() == 0) {
        ht[node] = 0;
        return 0;
    }
    int h_max = 0, h;
    for (auto ptr = c[node].first(); ptr != c[node].last()->succ; ptr = ptr->succ) {
        h = getHeight(ht, c, ptr->data);
        if (h > h_max)
            h_max = h;
    }
    ht[node] = h_max + 1;
    return h_max + 1;
}

void updateHeightAbove(int *ht, int *p, List<int> *c, int node, char op) {
    if (op == 'i') {
        while (p[node] != 0) {
            if (ht[node] + 1 <= ht[p[node]])
                break;
            else {
                ht[p[node]] = ht[node] + 1;
                node = p[node];
            }
        }
    } else if (op == 'r') {
        while (p[node] != 0) {
            if (ht[node] + 1 < ht[p[node]])
                break;
            else {
                if (c[p[node]].size() == 1)
                    ht[p[node]] = 0;
                else {
                    ht[p[node]] = 0;
                    for (auto ptr = c[p[node]].first(); ptr != c[p[node]].last()->succ; ptr = ptr->succ) {
                        if (ptr->data != node && ht[ptr->data] + 1 > ht[p[node]])
                            ht[p[node]] = ht[ptr->data] + 1;
                    }
                }
                node = p[node];
            }
        }
    }
}

int getSize(int *s, List<int> *c, int node) {
    if (c[node].size() == 0) {
        s[node] = 1;
        return 1;
    }
    int sz = 0;
    for (auto ptr = c[node].first(); ptr != c[node].last()->succ; ptr = ptr->succ) {
        sz += getSize(s, c, ptr->data);
    }
    s[node] = sz + 1;
    return sz + 1;
}

void updateSizeAbove(int *s, int *p, List<int> *c, int node, char op) {
    int sz = s[node];
    if (op == 'i') {
        while (p[node] != 0) {
            s[p[node]] += sz;
            node = p[node];
        }
    } else if (op == 'r') {
        while (p[node] != 0) {
            s[p[node]] -= sz;
            node = p[node];
        }
    }
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
    // 初始化高度和大小
    int *height = new int[n + 1], *size = new int[n + 1];
    getHeight(height, c, 1);
    getSize(size, c, 1);
    // 移动
    int src, dst, r;
    Posi<int> p_src, p_dst;
    int q, qn;
    for (int i = 0; i != m; ++i) {
        scanf("%d", &q);
        if (q == 0) {
            // 源节点
            p_src = getNode(p, c);
            src = p_src->data;
            updateHeightAbove(height, p, c, src, 'r');
            updateSizeAbove(size, p, c, src, 'r');
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
            updateHeightAbove(height, p, c, src, 'i');
            updateSizeAbove(size, p, c, src, 'i');
        } else if (q == 1) {
            qn = getNode(p, c)->data;
            printf("%d\n", height[qn]);
        } else if (q == 2) {
            qn = getNode(p, c)->data;
            printf("%d\n", size[qn]);
        }
    }
    return 0;
}
