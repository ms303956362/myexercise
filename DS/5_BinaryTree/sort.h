using Rank = int;

template <typename T>
void swap1(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void bubbleSort(T* const _elem, Rank lo, Rank hi) {
    for (Rank last = --hi; lo < hi; hi = last) 
        for (Rank i = last = lo; i < hi; ++i) 
            if (_elem[i] > _elem[i + 1]) {
                swap1(_elem[i], _elem[i + 1]);
                last = i;
            }
}

template <typename T>
void merge(T* const _elem, Rank lo, Rank mi, Rank hi) {
    int lb = mi - lo;
    int lc = hi - mi;
    T* A = _elem + lo, *B = new T[lb], *C = _elem + mi;
    for (Rank i = 0; i != lb; ++i) {
        B[i] = A[i];
    }
    for (Rank i = 0, j = 0, k = 0; j != lb; ) {
        if (k >= lc || B[j] <= C[k])
            A[i++] = B[j++];
        else
            A[i++] = C[k++];
    }
    delete [] B;
}

template <typename T>
void mergeSort(T* const _elem, Rank lo, Rank hi) {
    if (hi - lo < 2)
        return;
    Rank mi = (lo + hi) / 2;
    mergeSort(_elem, lo, mi);
    mergeSort(_elem, mi, hi);
    merge(_elem, lo, mi, hi);
}
