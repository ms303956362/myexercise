#include "usual.h"

int is_prime[100005], prime[100005];
vector<int> ps;
bool is_init = false;
int Eratosthenes(int n) {
  int p = 0;
  for (int i = 0; i <= n; ++i) is_prime[i] = 1;
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      prime[p++] = i;  // prime[p]是i,后置自增运算代表当前素数数量
      if ((long long)i * i <= n)
        for (int j = i * i; j <= n; j += i)
          // 因为从 2 到 i - 1 的倍数我们之前筛过了，这里直接从 i
          // 的倍数开始，提高了运行速度
          is_prime[j] = 0;  // 是i的倍数的均不是素数
    }
  }
  return p;
}

class Solution {
public:
    int smallestValue(int n) {
        if (!is_init) {
            Eratosthenes(100003);
            ps.clear();
            for (int i = 2; i <= 100002; ++i) {
                if (is_prime[i]) {
                    ps.push_back(i);
                }
            }
            is_init = true;
        }
        int m = ps.size();
        auto check = [&](int k) {
            int sum = 0;
            for (int i = 0; i < m && ps[i] < k; ++i) {
                while (k % ps[i] == 0) {
                    sum += ps[i];
                    k /= ps[i];
                }
            }
            return sum;
        };
        while (!is_prime[n]) {
            n = check(n);
        }
        return n;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
