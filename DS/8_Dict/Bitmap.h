#pragma once
#include <cstdlib>
#include <cstring>

class Bitmap {
private:
    char *M;
    int N;

protected:
    void init(int n);

public:
    Bitmap(int n = 8) { init(n); }
    ~Bitmap() { delete M; M = nullptr; }
    void set(int k);
    void clear(int k);
    bool test(int k);
    void expand(int k);
};

/*********************保护*********************/
void Bitmap::init(int n) {
    N = (n + 7) / 8;
    M = new char[N];
    memset(M, 0, N);
}

/*******************对外接口*******************/
void Bitmap::set(int k) {
    expand(k);
    M[k >> 3] |= (0x80 >> (k & 0x07));
}

void Bitmap::clear(int k) {
    expand(k);
    M[k >> 3] &= ~(0x80 >> (k & 0x07));
}

bool Bitmap::test(int k) {
    expand(k);
    return M[k >> 3] & (0x80 >> (k & 0x07));
}

void Bitmap::expand ( int k ) { //若被访问的Bitmap[k]已出界，则需扩容
    // if ( k < 8 * N ) return; //仍在界内，无需扩容
    // int oldN = N; char* oldM = M;
    // init ( 2 * k ); //与向量类似，加倍策略
    // memcpy_s ( M, N, oldM, oldN ); delete [] oldM; //原数据转移至新空间
}
