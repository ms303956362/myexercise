#pragma once
using Rank = int;

template <typename T>
Rank binarySearch(T* const _elem, const T& e, Rank lo, Rank hi) {
    while (lo < hi) {
        Rank mi = (lo + hi) / 2;
        if (e < _elem[mi])
            hi = mi;
        else
            lo = mi + 1;
    }
    return --lo;
}

class Fib {
private:
    int f;
    int g;

public:
    Fib(int n) : f(1), g(1) { while (g < n) next(); }
    int get() { return g; }
    int prev() { f = g - f; g -= f; return g;}
    int next() { g += f; f = g - f; return g;}
};

template <typename T>
Rank fibSearch(T* const _elem, const T& e, Rank lo, Rank hi) {
    auto fib = Fib(hi - lo);
    while (lo < hi) {
        while (fib.get() > (hi - lo))
            fib.prev();
        Rank mi = lo + fib.get() - 1;
        if (e < _elem[mi])
            hi = mi;
        else
            lo = mi + 1;
    }
    return --lo;
}
