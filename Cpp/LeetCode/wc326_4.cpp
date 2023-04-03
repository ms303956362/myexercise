#include "usual.h"

int is_prime[1000005], prime[1000005];
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
    vector<int> closestPrimes(int left, int right) {
        if (!is_init) {
            Eratosthenes(1000003);
            ps.clear();
            for (int i = 2; i <= 1000002; ++i) {
                if (is_prime[i]) {
                    ps.push_back(i);
                }
            }
            is_init = true;
        }
        int l = lower_bound(ps.begin(), ps.end(), left) - ps.begin(), r = upper_bound(ps.begin(), ps.end(), right) - ps.begin() - 1;
        if (l >= r) {
            return {-1, -1};
        }
        int min_diff = INT_MAX;
        vector<int> ans{-1, -1};
        for (int i = l; i < r; ++i) {
            if (ps[i + 1] - ps[i] < min_diff) {
                min_diff = ps[i + 1] - ps[i];
                ans = vector<int>{ps[i], ps[i + 1]};
            }
        }
        return ans;
    }
};