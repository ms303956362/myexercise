#include "usual.h"

int solution(vector<int> &X, vector<int> &Y, int W) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    sort(X.begin(), X.end());
    int ans = 0, n = X.size();
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && X[j] - X[i] <= W) {
            ++j;
        }
        ++ans;
        i = j;
    }
    return ans;
}