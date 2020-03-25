#include <cstdio>
#include "List.h"

const int UNDISCOVERED = 0, DISCOVERED = 1, VISITED = 2;

class GraphTable{
private:
    int* status;
    int *max_v_num;
    List<int>* outNbr;

public:
    int n;
    int e;
    // 构造
    GraphTable(int num = 0) : n(num), e(0) {
        status = new int[n];
        max_v_num = new int[n];
        for (int i = 0; i != n; ++i){
            status[i] = 0;
            max_v_num[i] = 1;
        }
        outNbr = new List<int>[n];
    };

    void insertEdge(int v, int u) {
        outNbr[v].insertAsLast(u);
        ++e;
    }

    int tsp() {
        int max_v_num = 0;
        int v_num;
        for (int v = 0; v != n; ++v) {
            if (status[v] == UNDISCOVERED) {
                v_num = TSP(v);
                if (v_num > max_v_num)
                    max_v_num = v_num;
            }
        }
        return max_v_num;
    }

    int TSP(int v) {
        int v_num;
        status[v] = DISCOVERED;
        for (Posi<int> p = outNbr[v].first(); p != outNbr[v].last()->succ; p = p->succ) {
            int u = p->data;
            switch (status[u]) {
            case UNDISCOVERED:
                v_num = TSP(u);
                if (v_num + 1 > max_v_num[v])
                    max_v_num[v] = v_num + 1;
                break;
            
            case VISITED:
                if (max_v_num[u] + 1 > max_v_num[v])
                    max_v_num[v] = max_v_num[u] + 1;
                break;

            default:
                break;
            }
        }
        status[v] = VISITED;
        return max_v_num[v];
    }
};

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    int n, m;
    scanf("%d %d", &n, &m);
    GraphTable g(n);
    for (int i = 0; i != m; ++i) {
        int v, u;
        scanf("%d %d", &v, &u);
        g.insertEdge(v - 1, u - 1);
    }
    int num = g.tsp();
    printf("%d", num);
    return 0;
}
