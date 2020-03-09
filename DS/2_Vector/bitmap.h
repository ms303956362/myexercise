using Rank = int;
class Bitmap {
private:
    Rank *F;
    Rank *T;
    Rank top;
    Rank N;

public:
    Bitmap(Rank n);
    ~Bitmap();
    void set(Rank k);
    void clear(Rank k);
    void reset() { top = 0; }
    Rank getNum() { return top; }
    bool test(Rank k);
};

inline
Bitmap::Bitmap(Rank n = 0): top(0), N(n) {
    F = new Rank[N];
    T = new Rank[N];
}

inline
Bitmap::~Bitmap() {
    delete[] F;
    delete[] T;
}

inline
void Bitmap::set(Rank k) {
    if (!test(k)) {
        F[k] = top;
        T[top++] = k;
    }
}

inline
void Bitmap::clear(Rank k) {
    if (test(k) && --top) {
        F[T[top]] = F[k];
        T[F[k]] = T[top];
    }
}

inline
bool Bitmap::test(Rank k) {
    return 0 <= F[k] && F[k] < top && T[F[k]] == k;
}
