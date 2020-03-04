#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstdio>

// #include "Vector.h"

int search(int *a, int e, int lo, int hi) {
    int mi;
    while (lo < hi) {
        mi = (hi + lo) / 2;
        if (e < a[mi])
            hi = mi;
        else
            lo = mi + 1;
    }
    return --lo;
}

void merge(int *a, int lo, int mi, int hi) {
    int lb = mi - lo, lc = hi - mi;
    int *A = a + lo, *B = new int[lb], *C = a + mi;
    for (int i = 0; i != lb; ++i)
        B[i] = A[i];
    for (int i = 0, j = 0, k = 0; j < lb;) {
        if ( k >= lc || B[j] <= C[k])
            A[i++] = B[j++];
        else
            A[i++] = C[k++];
    }
    delete[] B;
}

void mergeSort(int *a, int lo, int hi) {
    if (hi - lo < 2)
        return;
    int mi = (lo + hi) / 2;
    mergeSort(a, lo, mi);
    mergeSort(a, mi, hi);
    merge(a, lo, mi, hi);
}


int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    // Vector<int> v;
    int* v = new int[n];
    int a, lo, hi;
    for (int i = 0; i != n; ++i) {
        scanf("%d", &a);
        // v.insert(a);
        v[i] = a;
    }
    // v.sort();
    mergeSort(v, 0, n);
    for (int i = 0; i != m; ++i) {
        scanf("%d %d", &lo, &hi);
        // lo = v.search(lo - 1);
        // hi = v.search(hi); 
        lo = search(v, lo - 1, 0, n);
        hi = search(v, hi, 0, n);
        printf("%d\n", hi - lo);
    }
    return 0;
}
