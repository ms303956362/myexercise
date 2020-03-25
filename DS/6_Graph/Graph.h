#include "Stack.h"
#include "Queue.h"
#include <climits>

enum VStatus { UNDISCOVERED, DISCOVERED, VISITED };
enum EType {UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD};

template <typename Tv, typename Te>
class Graph {
private:
    void reset() { // 清空算法相关变量，保留数据、拓扑（含权重）信息
        for (int i = 0; i != n; ++i) {
            // 顶点
            status(i) = UNDISCOVERED;
            dTime(i) = -1;
            fTime(i) = -1;
            parent(i) = -1;
            priority(i) = INT_MAX;
            // 边
            for (int j = 0; j != n; ++j) {
                if (exists(i, j))
                    type(i, j) = UNDETERMINED;
            }
        }
    }
    void BFS(int v, int &clock);    // 连通域广度优先搜索
    void DFS(int v, int &clock, int ver);    // 连通域深度优先搜索
    void BCC(int v, int &clock, Stack<int> &s);   // 连通域DFS的双连通分量分解
    bool TSort(int v, int &clock, Stack<Tv> *s); // 连通域DFS的拓扑排序
    template <typename PU> void PFS(int v, PU prioUpdater); // 连通域优先搜索框架

public:
    // 顶点
    int n;
    virtual int insert(const Tv &d) = 0;
    virtual Tv remove(int v) = 0;
    virtual Tv &vertex(int i) = 0;
    virtual int inDegree(int i) = 0;
    virtual int outDegree(int i) = 0;
    virtual int firstNbr(int i) = 0;
    virtual int nextNbr(int i, int j) = 0;
    virtual VStatus &status(int i) = 0;
    virtual int &dTime(int i) = 0;
    virtual int &fTime(int i) = 0;
    virtual int &hca(int i) = 0;
    virtual int &priority(int i) = 0;
    virtual int &parent(int i) = 0;
    // 边
    int e;
    virtual bool exists(int i, int j) = 0;
    virtual void insert(const Te &d, int w, int i, int j) = 0;
    virtual Te remove(int i, int j) = 0;
    virtual EType &type(int i, int j) = 0;
    virtual Te &edge(int i, int j) = 0;
    virtual int &weight(int i, int j) = 0;
    // 算法
    void bfs(int i);
    void dfs(int i, int ver);
    void bcc(int i);
    Stack<Tv> *tSort(int i);
    void prim(int i);
    void dijkstra(int i);
    template <typename PU> void pfs(int v, PU prioUpdater);
};

/************************连通域操作************************/
template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int &clock) {
    Queue<int> q;
    q.enqueue(v);
    status(v) = DISCOVERED;
    while (!q.empty()) {
        int v = q.dequeue();
        dTime(v) = ++clock;
        // 访问节点操作

        // end 访问节点操作
        for (int u = firstNbr(v); u != -1; u = nextNbr(v, u)) {
            if (status(u) == UNDISCOVERED) {
                status(u) = DISCOVERED;
                type(v, u) = TREE;
                parent(u) = v;
                q.enqueue(u);
            } else { // DISCOVERED 或 VISITED
                type(v, u) = CROSS;
            }
        }
        status(v) = VISITED;
    }
}

class DFSTrackInfo {
public:
    int v;
    int u;
    DFSTrackInfo(int i = 0, int j = 0) : v(i), u(j){};
};

template <typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int v, int &clock, int ver) {
    if (ver == 0) { // 递归
        dTime(v) = ++clock;
        status(v) = DISCOVERED;
        // 访问节点操作

        // end 访问节点操作
        for (int u = firstNbr(v); u != -1; u = nextNbr(v, u)) {
            switch (status(u)) {
            case UNDISCOVERED:
                type(v, u) = TREE;
                parent(u) = v;
                DFS(u, clock, ver);
                break;
            case DISCOVERED:
                type(v, u) = BACKWARD;
                break;
            default:    // VISITED
                type(v, u) = dTime(v) < dTime(u) ? FORWARD : CROSS;
                break;
            }
        }
        fTime(v) = ++clock;
        status(v) = VISITED;
    } else if (ver == 1) { // 非递归
        Stack<DFSTrackInfo> s;
        s.push(DFSTrackInfo(v, firstNbr(v)));
        while (!s.empty()) {
            v = s.top().v;  // 判别栈顶元素
            if (status(v) == UNDISCOVERED) {  // 未发现过，打时间戳
                dTime(v) = ++clock;
                status(v) = DISCOVERED;
                // 访问节点操作

                // end 访问节点操作
            }
            // 遍历邻居节点
            bool hasTreeEdge = false;
            for (int& u = s.top().u; u != -1 && !hasTreeEdge;u = nextNbr(v, u)) {
                switch (status(u)) { // u是s.top().u的引用，会改变栈顶的u
                case UNDISCOVERED:
                    type(v, u) = TREE;
                    parent(u) = v;
                    s.push(DFSTrackInfo(u, firstNbr(u)));
                    hasTreeEdge = true;
                    break;
                case DISCOVERED:
                    type(v, u) = BACKWARD;
                    break;
                default:    // VISITED
                    type(v, u) = dTime(v) < dTime(u) ? FORWARD : CROSS;
                    break;
                }
            }
            if (!hasTreeEdge) {
                s.pop();
                fTime(v) = ++clock;
                status(v) = VISITED;
            }
        }
    }
}

template <typename Tv, typename Te>
bool Graph<Tv, Te>::TSort(int v, int &clock, Stack<Tv> *s) {
    dTime(v) = ++clock;
    status(v) = DISCOVERED;
    for (int u = firstNbr(v); u != -1; u = nextNbr(v, u)) {
        switch (status(u)) {
        case UNDISCOVERED:
            type(v, u) = TREE;
            parent(u) = v;
            if (!TSort(u, clock, s))
                return false;
            break;
        
        case DISCOVERED:
            return false;

        default: // VISITED
            type(v, u) = dTime(v) < dTime(u) ? FORWARD : CROSS;
            break;
        }
    }
    fTime(v) = ++clock;
    status(v) = VISITED;
    s->push(vertex(v));
    return true;
}

template <typename Tv, typename Te>
template <typename PU>
void Graph<Tv, Te>::PFS(int v, PU prioUpdater) {
    priority(v) = 0;
    status(v) = VISITED;
    parent(v) = -1;
    while (1) {
        for (int w = firstNbr(v); w != -1; w = nextNbr(v, w)) { // 更新v邻居优先级
            prioUpdater(this, v, w);
        }
        for (int min_prio = INT_MAX, w = 0; w != n; ++w) {
            if (status(w) == UNDISCOVERED && priority(w) < min_prio) {
                min_prio = priority(w);
                v = w;
            }
        }
        if (status(v) == VISITED)
            break;
        status(v) = VISITED;
        type(parent(v), v) = TREE;
    }
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::BCC(int v, int &clock, Stack<int> &s) {
    dTime(v) = ++clock;
    hca(v) = dTime(v);
    status(v) = DISCOVERED;
    s.push(v);
    for (int u = firstNbr(v); u != -1; u = nextNbr(v, u)) {
        switch (status(u)) {
        case UNDISCOVERED:
            type(v, u) = TREE;
            parent(u) = v;
            BCC(u, clock, s);
            if (hca(u) < dTime(v)) { // u的最高可达祖先在v之前
                if (hca(u) < hca(v))
                    hca(v) = hca(u);
            } else {  //u的最高可达祖先不超过v，v是关节点
                while (u != s.pop())
                    ;
            }
            break;
        
        case DISCOVERED:
            if (dTime(u) < hca(v))
                hca(v) = dTime(u);
            type(v, u) = BACKWARD;
            break;
        
        default:  // VISITED
            type(v, u) = dTime(v) < dTime(u) ? FORWARD : CROSS;
            break;
        }
    }
    status(v) = VISITED;
}

/***********************全图操作**************************/
template <typename Tv, typename Te>
void Graph<Tv, Te>::bfs(int v) {
    reset();
    int clock = 0;
    int s = v;
    do {
        if (status(v) == UNDISCOVERED) 
            BFS(v, clock);
        v = (v + 1) % n;
    } while (s != v);
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int v, int ver) {
    reset();
    int s = v;
    int clock = 0;
    do {
        if (status(v) == UNDISCOVERED) 
            DFS(v, clock, ver);
        v = (v + 1) % n;
    } while (v != s);
}

template <typename Tv, typename Te>
Stack<Tv> *Graph<Tv, Te>::tSort(int v) {
    reset();
    int s = v;
    int clock = 0;
    Stack<Tv>* S = new Stack<Tv>();
    do {
        if (status(v) == UNDISCOVERED) {
            if (!TSort(v, clock, S)) {
                while (!S->empty())
                    S->pop();
                break;
            }
        }
        v = (v + 1) % n;
    } while (v != s);
    return S;
}

template <typename Tv, typename Te>
template <typename PU>
void Graph<Tv, Te>::pfs(int v, PU prioUpdater) {
    reset();
    int s = v;
    do {
        if (status(v) == UNDISCOVERED)
            PFS(v, prioUpdater);
        v = (v + 1) % n;
    } while (v != s);
}

template <typename Tv, typename Te>
class PrimUpdater {
public:
    void operator()(Graph<Tv, Te> *g, int v, int w) {
        if (g->status(w) != UNDISCOVERED)
            return;
        if (g->priority(w) > g->weight(v, w)) {
            g->priority(w) = g->weight(v, w);
            g->parent(w) = v;
        }
    }
};

template <typename Tv, typename Te>
void Graph<Tv, Te>::prim(int v) {
    pfs(v, PrimUpdater<Tv, Te>());
}

template <typename Tv, typename Te>
class DijkstraUpdater {
public:
    void operator()(Graph<Tv, Te> *g, int v, int w) {
        if (g->status(w) != UNDISCOVERED)
            return;
        if (g->priority(w) > g->weight(v, w) + g->priority(v)) {
            g->priority(w) = g->weight(v, w) + g->priority(v);
            g->parent(w) = v;
        }
    }
};

template <typename Tv, typename Te>
void Graph<Tv, Te>::dijkstra(int v) {
    pfs(v, DijkstraUpdater<Tv, Te>());
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::bcc(int v) {

}
