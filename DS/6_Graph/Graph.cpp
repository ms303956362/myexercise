#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#define DEBUG
#include "GraphMatrix.h"

const char tv[3] = {'U', 'D', 'V'};
const char te[5] = {'U', 'T', 'C', 'F', 'B'};

template <typename Tv, typename Te>
ostream& printMatrix(ostream& os, Graph<Tv, Te>& g, Tv* vnames = nullptr) {
    for (int i = 0; i != g.n; ++i) {
        for (int j = 0; j != g.n; ++j) {
            if (vnames) {
                if (g.exists(i, j))
                    os << vnames[i] << "->" << vnames[j] << ": " << te[g.type(i, j)] << "   ";
            } else {
                os << (g.exists(i, j) ? te[g.type(i, j)] : '*') << " ";
            }
        }
        os << endl;
    }
    return os;
}

template <typename Tv, typename Te>
ostream& printTime(ostream& os, Graph<Tv, Te>& g, Tv* vnames) {
    os << "names: ";
    for (int i = 0; i != g.n; ++i) {
        os << vnames[i] << "  ";
    }
    os << endl;
    os << "dTime: ";
    for (int i = 0; i != g.n; ++i) {
        int t = g.dTime(i);
        os << t << (t < 10 ? "  " : " ");
    }
    os << endl;
    os << "fTime: ";
    for (int i = 0; i != g.n; ++i) {
        int t = g.fTime(i);
        os << t << (t < 10 ? "  " : " ");
    }
    os << endl;
    return os;
}

int main(int argc, char const *argv[])
{
    // 测试生成图
    cout << "test graph" << endl;
    GraphMatrix<char, int> g0;
    char v0[4] = {'A', 'B', 'C', 'D'};
    for (int i = 0; i != 4; ++i)
        g0.insert(v0[i]);
    g0.insert('E');
    g0.insert(3, 3, 0, 2);
    g0.insert(4, 4, 2, 0);
    g0.insert(7, 7, 1, 0);
    g0.insert(9, 9, 1, 2);
    g0.insert(6, 6, 2, 1);
    g0.remove(2, 1);
    g0.insert(2, 2, 1, 3);
    g0.insert('F');
    g0.remove(5);
    g0.remove(4);
    g0.insert(5, 5, 3, 1);
    printMatrix(cout, g0) << endl;

    // 测试bfs
    cout << "test bfs" << endl;
    char v1[8] = {'g', 'f', 'e', 'd', 'c', 'b', 'a', 's'};
    int a1[8][8] = {
            /* s  a  b  c  d  e  f  g*/
        /*s*/ {0, 1, 0, 1, 1, 0, 0, 0},
        /*a*/ {1, 0, 0, 1, 0, 1, 0, 0},
        /*b*/ {0, 0, 0, 1, 1, 0, 0, 1},
        /*c*/ {1, 1, 1, 0, 0, 0, 0, 0},
        /*d*/ {1, 0, 1, 0, 0, 0, 0, 0},
        /*e*/ {0, 1, 0, 0, 0, 0, 1, 1},
        /*f*/ {0, 0, 0, 0, 0, 1, 0, 1},
        /*g*/ {0, 0, 1, 0, 0, 1, 1, 0}
    };
    GraphMatrix<char, int> g1;
    for (int i = 0; i != 8; ++i) {
        g1.insert(v1[i]);
    }
    for (int i = 0; i != 8; ++i) {
        for (int j = 0; j != 8; ++j) {
            if (a1[i][j] == 1)
                g1.insert(0, 0, 7 - i, 7 - j);
        }
    }
    g1.bfs(7);
    printTime(cout, g1, v1);
    printMatrix(cout, g1, v1) << endl;

    // 测试递归dfs
    cout << "test dfs recursion" << endl;
    char v2[7] = {'g', 'f', 'd', 'e', 'c', 'b', 'a'};
    int a2[7][7] = {
            /* a  b  c  e  d  f  g*/
        /*a*/ {0, 1, 1, 0, 0, 1, 0},
        /*b*/ {0, 0, 1, 0, 0, 0, 0},
        /*c*/ {0, 0, 0, 0, 0, 0, 0},
        /*e*/ {0, 0, 0, 0, 0, 1, 0},
        /*d*/ {1, 0, 0, 1, 0, 0, 0},
        /*f*/ {0, 0, 0, 0, 0, 0, 1},
        /*g*/ {1, 0, 1, 0, 0, 0, 0},
    };
    GraphMatrix<char, int> g2;
    for (int i = 0; i != 7; ++i ) {
        g2.insert(v2[i]);
    }
    for (int i = 0; i != 7; ++i ) {
        for (int j = 0; j != 7; ++j) {
            if (a2[i][j])
                g2.insert(0, 0, 6 - i, 6 - j);
        }
    }
    g2.dfs(6, 0);
    printTime(cout, g2, v2);
    printMatrix(cout, g2, v2) << endl;
    // 测试非递归dfs
    cout << "test dfs none-recursion" << endl;
    char v3[7] = {'g', 'f', 'd', 'e', 'c', 'b', 'a'};
    int a3[7][7] = {
            /* a  b  c  d  e  f  g*/
        /*a*/ {0, 1, 1, 0, 0, 1, 0},
        /*b*/ {0, 0, 1, 0, 0, 0, 0},
        /*c*/ {0, 0, 0, 0, 0, 0, 0},
        /*e*/ {0, 0, 0, 0, 0, 1, 0},
        /*d*/ {1, 0, 0, 1, 0, 0, 0},
        /*f*/ {0, 0, 0, 0, 0, 0, 1},
        /*g*/ {1, 0, 1, 0, 0, 0, 0},
    };
    GraphMatrix<char, int> g3;
    for (int i = 0; i != 7; ++i ) {
        g3.insert(v3[i]);
    }
    for (int i = 0; i != 7; ++i ) {
        for (int j = 0; j != 7; ++j) {
            if (a3[i][j])
                g3.insert(0, 0, 6 - i, 6 - j);
        }
    }
    g3.dfs(6, 1);
    printTime(cout, g3, v3);
    printMatrix(cout, g3, v3) << endl;

    // 测试tSort
    cout << "test tSort" << endl;
    char v4[6] = {'F', 'E', 'D', 'C', 'B', 'A'};
    int a4[6][6] = {
            /* A  B  C  D  E  F */
        /*A*/ {0, 0, 1, 1, 0, 0},
        /*B*/ {0, 0, 1, 0, 0, 0},
        /*C*/ {0, 0, 0, 1, 1, 1},
        /*D*/ {0, 0, 0, 0, 0, 0},
        /*E*/ {0, 0, 0, 0, 0, 1},
        /*F*/ {0, 0, 0, 0, 0, 0},
    };
    GraphMatrix<char, int> g4;
    for (int i = 0; i != 6; ++i ) {
        g4.insert(v4[i]);
    }
    for (int i = 0; i != 6; ++i ) {
        for (int j = 0; j != 6; ++j) {
            if (a4[i][j])
                g4.insert(0, 0, 5 - i, 5 - j);
        }
    }
    auto s_tsort = g4.tSort(3);
    while (!s_tsort->empty())
        cout << s_tsort->pop() << " ";
    cout << endl << endl;

    // 测试prim
    cout << "test prim" << endl;
    char v5[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int a5[8][8] = {
            /* A  B  C  D  E  F  G  H*/
        /*A*/ {0, 4, 0, 6, 0, 0, 7, 0},
        /*B*/ {4, 0, 12,0, 0, 0, 0, 0},
        /*C*/ {0, 12,0, 9, 1, 2, 0, 10},
        /*D*/ {6, 0, 9, 0, 13,0, 2, 0},
        /*E*/ {0, 0, 1, 13,0, 5, 0, 8},
        /*F*/ {0, 0, 2, 0, 5, 0, 0, 7},
        /*G*/ {7, 0, 0, 2, 11,0, 0, 14},
        /*H*/ {0, 0, 10,0, 8, 7, 14, 0}
    };
    GraphMatrix<char, int> g5;
    for (int i = 0; i != 8; ++i) {
        g5.insert(v5[i]);
    }
    for (int i = 0; i != 8; ++i) {
        for (int j = 0; j != 8; ++j) {
            if (a5[i][j])
                g5.insert(0, a5[i][j], i, j);
        }
    }
    g5.prim(0);
    printMatrix(cout, g5, v5) << endl;

    // 测试dijkstra
    cout << "test dijkstra" << endl;
    g5.remove(5, 7);
    g5.remove(7, 5);
    g5.insert(0, 3, 5, 7);
    g5.insert(0, 3, 7, 5);
    g5.dijkstra(0);
    for (int i = 0; i != 8; ++i) {
        cout << v5[0] << "->" << v5[i] << ": " << g5.priority(i) << "  ";
    }
    cout << endl;
    return 0;
}
