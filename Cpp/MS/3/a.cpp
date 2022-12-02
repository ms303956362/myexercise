#include "usual.h"

int solution(int M, int N) {
  // write your code in C++ (C++14 (g++ 6.2.0))
  long long area = 0;
  if (N > 0) {
    int t = sqrt(N);
    t <<= 1;
    area = (long long)(t) * (long long)(t);
    int d = M - (area + ((long long)(t + 1 - N) << 2));
    if (d >= 0) {
      area += ((long long)(t + 1) << 2);
      M = d;
    }
  }
  return sqrt(area + M);
}

int main(int argc, char const *argv[])
{
    cout << solution(5, 1) << endl;
    return 0;
}
