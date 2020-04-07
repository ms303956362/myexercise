#include <cstdio>
#include <cstring>
#include "Queue.h"

class V;
using VP = V *;

class V {
public:
    int v;
    VP next;
    V(int v = 0, VP n = nullptr): v(v), next(n) {}
};

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    char* vst = new char[n];
    memset(vst, 0, n * sizeof(char));
    VP g = new V[n];
    for (int i = 0; i != n; ++i) {
        g[i].v = i;
    }
    int v1, v2;
    for (int i = 0; i != m; ++i) {
        scanf("%d %d", &v1, &v2);
        g[v1 - 1].next = new V(v2 - 1, g[v1 - 1].next);
        g[v2 - 1].next = new V(v1 - 1, g[v2 - 1].next);
    }
    Queue<int> q;
    q.enqueue(0);
    vst[0] = 1;
    int res = 1;
    while (!q.empty())
    {
        int v = q.dequeue();
        int nbr_vst = vst[v] == 1 ? 2 : 1;
        for (VP p = g[v].next; p != nullptr; p = p->next) {
            if (vst[p->v] == 0) {
                vst[p->v] = nbr_vst;
                q.enqueue(p->v);
            } else if (vst[p->v] == vst[v]) {
                res = -1;
                break;
            }
        }
        if (res == -1)
            break;
    }
    printf("%d", res);
    return 0;
}
