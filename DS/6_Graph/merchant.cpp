#include <cstdio>
#include "List.h"

const int UNDISCOVERED = 0, DISCOVERED = 1, VISITED = 2;

struct Edge {
    int u;
    int p;
    Edge(int n = 0, int pr = 0) : u(n), p(pr) {}
};

class GraphTable{
public:
    GraphTable(int num) : n(num), e(0) {
        status = new int[num];
        max_price = new int[num];
        outNbr = new List<Edge>[num];
        for (int i = 0; i != num; ++i) {
            status[i] = UNDISCOVERED;
            max_price[i] = 0;
        }
    }

    void insertEdge(int v, int u, int p) { // v->u
        Edge E(u, p);
        outNbr[v].insertAsLast(E);
        ++e;
    }

    int tsp() {
        int max_p = 0;
        for (int v = 0; v != n; ++v) {
            if (status[v] == UNDISCOVERED) {
                int p = TSP(v);
                if (p > max_p)
                    max_p = p;
            }
        }
        return max_p;
    }

private:
    int n;
    int e;
    int* status;
    int *max_price;
    List<Edge>* outNbr;

    int TSP(int v) {
        for (Posi<Edge> p = outNbr[v].first(); p != outNbr[v].last()->succ; p = p->succ) {
            int u = p->data.u;
            int price = p->data.p;
            int up;
            switch (status[u]) {
            case UNDISCOVERED:
                status[u] = DISCOVERED;
                up = TSP(u);
                if (price + up > max_price[v])
                    max_price[v] = price + up;
                break;
            case VISITED:
                if (price + max_price[u] > max_price[v])
                    max_price[v] = price + max_price[u];
                break;
            default:
                break;
            }
        }
        status[v] = VISITED;
        return max_price[v];
    }
};

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    GraphTable g(n);
    int v, u, p;
    for (int i = 0; i != m; ++i) {
        scanf("%d %d %d", &v, &u, &p);
        g.insertEdge(v - 1, u - 1, p);
    }
    int res = g.tsp();
    printf("%d", res);
    return 0;
}
