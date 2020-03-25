#include "Graph.h"
#include "Vector.h"

/*******************顶点********************/
template <typename Tv>
class Vertex {
public:
    Tv data;
    VStatus status;
    int inDegree;
    int outDegree;
    int dTime;
    int fTime;
    int parent;
    int priority;
    Vertex(const Tv &d = static_cast<Tv>(0)) : 
        data(d), status(UNDISCOVERED), inDegree(0), outDegree(0), 
        dTime(-1), fTime(-1), parent(-1), priority(INT_MAX){};
};

/********************边********************/
template <typename Te>
class Edge {
public:
    Te data;
    int weight;
    EType type;
    Edge(const Te &d, int w) : data(d), weight(w), type(UNDETERMINED){};
};

/*****************邻接矩阵*****************/
template <typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te> {
private:
    Vector<Vertex<Tv>> V;
    Vector<Vector<Edge<Te>*>> E;
public:
    // 构造和析构函数
    GraphMatrix() { this->n = 0; this->e = 0; } // inline
    ~GraphMatrix();
    // 顶点基本操作
    Tv &vertex(int i) { return V[i].data; } // inline
    int inDegree(int i) { return V[i].inDegree; } // inline
    int outDegree(int i) { return V[i].outDegree; } // inline
    int firstNbr(int i) { return nextNbr(i, this->n); } // inline
    int nextNbr(int i, int j);
    VStatus &status(int i) { return V[i].status; } // inline
    int &dTime(int i) { return V[i].dTime; } // inline
    int &fTime(int i) { return V[i].fTime; } // inline
    int &hca(int i) { return V[i].fTime; } // inline
    int &priority(int i) { return V[i].priority; } // inline
    int &parent(int i) { return V[i].parent; } // inline
    // 顶点动态操作
    int insert(const Tv &d);
    Tv remove(int i);
    // 边基本操作
    bool exists(int i, int j) { return 0 <= i && i < this->n && 0 <= j && j < this->n && E[i][j] != nullptr; } // inline
    EType &type(int i, int j) { return E[i][j]->type; } // inline
    Te &edge(int i, int j) { return E[i][j]->data; } // inline
    int &weight(int i, int j) { return E[i][j]->weight; } // inline
    // 边动态操作
    void insert(const Te &d, int w, int i, int j);
    Te remove(int i, int j);
};

/*******************构造和析构函数********************/
template <typename Tv, typename Te>
GraphMatrix<Tv, Te>::~GraphMatrix() {
    for (int i = 0; i != this->n; ++i) {
        for (int j = 0; j != this->n; ++j) {
            delete E[i][j];
        }
    }
}

/********************顶点基本操作********************/
template <typename Tv, typename Te>
inline int GraphMatrix<Tv, Te>::nextNbr(int i, int j) {
    while (--j >= 0 && !exists(i, j))
        ;
    return j;
}

/********************顶点动态操作********************/
template <typename Tv, typename Te>
int GraphMatrix<Tv, Te>::insert(const Tv &d) {
    for (int i = 0; i != this->n; ++i) {
        E[i].insert(nullptr);
    }
    ++this->n;
    E.insert(Vector<Edge<Te> *>(this->n, nullptr, this->n));
    return V.insert(Vertex<Tv>(d));
}

template <typename Tv, typename Te>
Tv GraphMatrix<Tv, Te>::remove(int i) {
    for (int j = 0; j != this->n; ++j) {  // 释放第i行各元素指向内存E[i, :]
        if (exists(i, j)) {
            delete E[i][j];
            --V[j].inDegree;
            --this->e;
        }
    }
    E.remove(i); // 删除第i行
    --this->n;
    Tv tmp = vertex(i);
    V.remove(i); // 先删除，否则后面V[j]对不上
    for (int j = 0; j != this->n; ++j) {
        Edge<Te> *p = E[j].remove(i);   // 其余各行删除第i列元素E[:, i]
        if (p) {    // 不是空指针要释放内存
            delete p;
            --V[j].outDegree;
            --this->e;
        }
    }
    return tmp;
}

/*********************边动态操作********************/
template <typename Tv, typename Te>
void GraphMatrix<Tv, Te>::insert(const Te &d, int w, int i, int j) {
    if (exists(i, j))
        return;
    E[i][j] = new Edge<Te>(d, w);
    ++this->e;
    ++V[i].outDegree;
    ++V[j].inDegree;
}

template <typename Tv, typename Te>
Te GraphMatrix<Tv, Te>::remove(int i, int j) {
    // E[i][j]为空的情况？
    Te tmp = edge(i, j);
    delete E[i][j];
    E[i][j] = nullptr;
    --this->e;
    --V[i].outDegree;
    --V[j].inDegree;
    return tmp;
}