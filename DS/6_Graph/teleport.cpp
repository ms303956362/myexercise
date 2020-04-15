#include <cstdio>
#include <cstring>
#include <climits>
#include "List.h"

int time = 0;

class GraphTable {
public:
    int *total;
    int *numM;
    int endV;
    int begV;
    GraphTable(int num) : n(num), top(-1) {
        numM = new int[num];
        total = new int[num];
        belong = new int[num];
        dTime = new int[num];
        low = new int[num];
        stack = new int[num];
        outNbr = new List<int>[num];
        inStack = new char[num];
        hasEnd = new char[num];
        memset(total, 0, num * sizeof(int));
        memset(dTime, 0, num * sizeof(int));
        memset(low, 0x3f, num * sizeof(int));
        memset(inStack, 0, num * sizeof(char));
        memset(hasEnd, 0, num * sizeof(char));
        for (int v = 0; v != num; ++v)
            belong[v] = v;
    }

    void insertEdge(int v, int u) {
        outNbr[v].insertAsLast(u);
    }

    void tarjan(int v) {
        for (int v = 0; v != n; ++v)
            if (!dTime[v])
                Tarjan(v);
    }

    void shrink() {
        for (int v = 0; v != n; ++v) {
            if (v == belong[v]) { // 强连通分量的超节点，向外邻居改为其超节点
                for (Posi<int> pu = outNbr[v].first(); pu != outNbr[v].last()->succ; ) {
                    int u = pu->data;  // 原邻居
                    if (belong[u] != v) { // 原邻居u不在v强连通分量内
                        pu->data = belong[u];
                        pu = pu->succ;
                    } else {// 原邻居u在v强连通分量内，删除
                        Posi<int> tmp = pu->succ;
                        outNbr[v].remove(pu);
                        pu = tmp;
                    }
                }
            } else { // 强连通分量内其他节点，向外邻居转接的超节点处
                for (Posi<int> pu = outNbr[v].first(); pu != outNbr[v].last()->succ; ) {
                    int u = pu->data;
                    if (u != belong[v] && belong[u] != belong[v]) { // 原邻居u不是v的超节点，且原邻居u的超节点与v的超节点不同
                        Posi<int> tmp = pu->succ;
                        outNbr[v].remove(pu);
                        outNbr[belong[v]].insertAsLast(belong[u]);
                        pu = tmp;
                    } else {
                        pu = pu->succ;
                    }
                }
            }
        }
        for (int v = 0; v != n; ++v) {
            if (v != belong[v])
                numM[belong[v]] += numM[v];
        }
        begV = belong[0];
        endV = belong[n - 1];
        memset(inStack, 0, n * sizeof(char));
    }

    void tSort(int v) {
        inStack[v] = 1;
        if (v == endV) {
            total[v] = numM[v];
            hasEnd[v] = 1;
            return;
        }
        int max_v = 0;
        for (Posi<int> pu = outNbr[v].first(); pu != outNbr[v].last()->succ; pu = pu->succ) {
            int u = pu->data;
            if (u != belong[u])
                continue;
            switch (inStack[u]) {
            case 0:
                tSort(u);
                if (hasEnd[u]) {
                    if (total[u] + numM[v] > max_v)
                        max_v = total[u] + numM[v];
                    hasEnd[v] = 1;
                }
                break;
            
            case 1:
                if (hasEnd[u]) {
                    if (total[u] + numM[v] > max_v)
                        max_v = total[u] + numM[v];
                    hasEnd[v] = 1;
                }
                break;

            default:
                break;
            }
        }
        total[v] = max_v;
    }

private: 
    int n;
    int top;
    int *belong;
    int *dTime;
    int *low;
    int *stack;
    List<int> *outNbr;
    char *inStack;
    char *hasEnd;

    void Tarjan(int v) {
        ++time;
        dTime[v] = low[v] = time;
        inStack[v] = 1;
        stack[++top] = v;
        for (Posi<int> pu = outNbr[v].first(); pu != outNbr[v].last()->succ; pu = pu->succ) {
            int u = pu->data;
            if (!dTime[u]) {
                Tarjan(u);
                low[v] = low[u] < low[v] ? low[u] : low[v];
            } else if (inStack[u]) {
                low[v] = low[u] < low[v] ? low[u] : low[v];
            }
        }
        if (dTime[v] == low[v]) {
            int u;
            while (stack[top] != v) {
                u = stack[top--];
                belong[u] = v;
                inStack[u] = 0;
            }
            inStack[v] = 0;
            top--;
        }
    }
};

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    char *s = new char[n + 1];
    scanf("%s", s);
    GraphTable g(n);
    for (int v = 0; v != n; ++v) {
        g.numM[v] = s[v] == 'M' ? 1 : 0;
    }
    int v, u;
    for (int i = 0; i != m; ++i) {
        scanf("%d %d", &v, &u);
        g.insertEdge(v, u);
    }
    g.tarjan(0);
    g.shrink();
    g.tSort(g.begV);
    printf("%d", g.total[g.begV]);
    return 0;
}
