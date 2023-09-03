#include "usual.h"

bool is_prime[4000005];
int prime[4000005];
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
    int diagonalPrime(vector<vector<int>>& nums) {
        if (!is_init) {
            Eratosthenes(4000002);
            is_init = true;
        }
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            if (is_prime[nums[i][i]]) {
                ans = max(ans, nums[i][i]);
            }
            if (is_prime[nums[i][n - i - 1]]) {
                ans = max(ans, nums[i][n - 1 - i]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
