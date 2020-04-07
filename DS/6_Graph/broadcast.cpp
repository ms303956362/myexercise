#include <cstdio>
#include "GraphMatrix.h"

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    GraphMatrix<char, char> g;
    int v1, v2;
    for (int i = 0; i != n; ++i) {
        g.insert(-1);
    }
    for (int i = 0; i != m; ++i) {
        scanf("%d %d", &v1, &v2);
        g.insert(0, 0, v1 - 1, v2 - 1);
        g.insert(0, 0, v2 - 1, v1 - 1);
    }
    int res = 1;
    Queue<int> q;
    q.enqueue(0);
    g.vertex(0) = 0;
    while(!q.empty()) {
        int v = q.dequeue();
        int nbr_data = g.vertex(v) == 0 ? 1 : 0;
        for (int u = g.firstNbr(v); u > -1; u = g.nextNbr(v, u)) {
            if (g.vertex(u) == g.vertex(v)) {
                res = -1;
                break;
            } else if (g.vertex(u) == -1) {
                g.vertex(u) = nbr_data;
                q.enqueue(u);
            }
        }
        if (res == -1)
            break;
    }
    printf("%d", res);
    return 0;
}
