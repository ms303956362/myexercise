#include <cstdio>
#include <climits>
#include <cstring>
#include "List.h"

const int UNDISCOVERED = 0, DISCOVERED = 1, VISITED = 2;

struct Edge {
    int u;
    int p;
    Edge(int n = 0, int pr = 0) : u(n), p(pr) {}
};

class GraphTable{
public:
    int *max_path;
    GraphTable(int num) : n(num), e(0) {
        status = new int[num];
        max_price = new int[num];
        max_path = new int[num + 1];
        outNbr = new List<Edge>[num];
        memset(status, UNDISCOVERED, num * sizeof(int));
        memset(max_price, 0, num * sizeof(int));
        memset(max_path, 0x3f, (num + 1) * sizeof(int));
    }

    void insertEdge(int v, int u, int p) { // v->u
        Edge E(u, p);
        outNbr[v].insertAsLast(E);
        ++e;
    }

    void tsp() {
        int max_p = 0;
        for (int v = 0; v != n; ++v) {
            if (status[v] == UNDISCOVERED) {
                TSP(v);
                if (max_price[v] > max_p) {
                    max_p = max_price[v];
                    max_path[n] = v;
                } else if (max_price[v] == max_p && v < max_path[n])
                    max_path[n] = v;
            }
        }
    }

private:
    int n;
    int e;
    int *status;
    int *max_price;
    List<Edge>* outNbr;

    void TSP(int v) {
        for (Posi<Edge> p = outNbr[v].first(); p != outNbr[v].last()->succ; p = p->succ) {
            int u = p->data.u;
            int price = p->data.p;
            int pr;
            switch (status[u]) {
            case UNDISCOVERED:
                status[u] = DISCOVERED;
                TSP(u);
                pr = price + max_price[u];
                if (pr > max_price[v]) {
                    max_price[v] = pr;
                    max_path[v] = u;
                }
                else if (pr == max_price[v] && u < max_path[v])
                    max_path[v] = u;
                break;
            case VISITED:
                pr = price + max_price[u];
                if (pr > max_price[v]) {
                    max_price[v] = pr;
                    max_path[v] = u;
                }
                else if (pr == max_price[v] && u < max_path[v])
                    max_path[v] = u;
                break;
            default:
                break;
            }
        }
        status[v] = VISITED;
    }
};

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    int n, m;
    scanf("%d %d", &n, &m);
    GraphTable g(n);
    int v, u, p;
    for (int i = 0; i != m; ++i) {
        scanf("%d %d %d", &v, &u, &p);
        g.insertEdge(v - 1, u - 1, p);
    }
    g.tsp();
    v = g.max_path[n];
    while (v < 1000000) {
        printf("%d ", v + 1);
        v = g.max_path[v];
    }
    return 0;
}
