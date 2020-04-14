#include <cstdio>
#include <cstring>
#include <climits>
#include "List.h"

template <class _Tp>
inline const _Tp& max(const _Tp& __a, const _Tp& __b) {
  return  __a < __b ? __b : __a;
}

template <class _Tp>
inline const _Tp& min(const _Tp& __a, const _Tp& __b) {
  return  __a < __b ? __a : __b;
}

int time = 0;

class GraphTable {
public:
    char *isM;
    GraphTable(int num) : n(num), top(-1) {
        isM = new char[num];
        belong = new int[num];
        dTime = new int[num];
        low = new int[num];
        stack = new int[num];
        outNbr = new List<int>[num];
        inStack = new char[num];
        memset(isM, 0, num * sizeof(char));
        memset(dTime, 0, num * sizeof(int));
        memset(low, 0x3f, num * sizeof(int));
        memset(inStack, 0, num * sizeof(char));
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
                for (Posi<int> pu = outNbr[v].first(); pu != outNbr[v].last()->succ; pu = pu->succ) {
                    int u = pu->data;
                    if (belong[v] != u && u != v) {
                        outNbr[v].insertAsLast(belong[u]);
                    }
                }
            }
        }
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