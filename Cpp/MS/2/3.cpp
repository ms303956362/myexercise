#include "usual.h"

int solution(vector<int> &A, int X, int Y) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int n = A.size();
    long long ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < Y; ++i) {
        int start = i, end = i;
        long long sum = 0;
        int j = 0;
        for (; end < n && j < X; ++j) {
            sum += A[end];
            end += Y;
        }
        if (j == X) {
            ans = min(ans, sum);
        }
        while (end < n) {
            sum -= A[start];
            sum += A[end];
            ans = min(ans, sum);
            start += Y;
            end += Y;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> A{4, 2, 5, 4, 3, 5, 1, 4, 2, 7};
    int X = 3;
    int Y = 2;
    cout << solution(A, X, Y) << endl;;
    return 0;
}
