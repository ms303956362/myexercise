#include "usual.h"

const int maxn = 1e6 + 5;
int is_prime[maxn], prime[maxn], m = 0;
bool prime_init = false;
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
    int findValidSplit(vector<int>& nums) {
        if (!prime_init) {
            prime_init = true;
            m = Eratosthenes(maxn - 1);
        }
        int n = nums.size();
        if (n == 1) {
            return -1;
        }
        vector<unordered_map<int, int>> cnt_num(n);
        unordered_map<int, int> cnt_pre, cnt_suf;
        for (int j = 1; j <= sqrt(nums[0]); ++j) {
            if (nums[0] % j == 0) {
                if (is_prime[j]) {
                    int c = 0, tmp = nums[0];
                    while (tmp % j == 0) {
                        ++c;
                        tmp /= j;
                    }
                    cnt_pre[j] += c;
                    cnt_num[0][j] += c;
                }
                if (j != nums[0] / j && is_prime[nums[0] / j]) {
                    int c = 0, tmp = nums[0];
                    while (tmp % (nums[0] / j) == 0) {
                        ++c;
                        tmp /= nums[0] / j;
                    }
                    cnt_pre[nums[0] / j] += c;
                    cnt_num[0][nums[0] / j] += c;
                }
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= sqrt(nums[i]); ++j) {
                if (nums[i] % j == 0) {
                    if (is_prime[j]) {
                        int c = 0, tmp = nums[i];
                        while (tmp % j == 0) {
                            ++c;
                            tmp /= j;
                        }
                        cnt_suf[j] += c;
                        cnt_num[i][j] += c;
                    }
                    if (j != nums[i] / j && is_prime[nums[i] / j]) {
                        int c = 0, tmp = nums[i];
                        while (tmp % (nums[i] / j) == 0) {
                            ++c;
                            tmp /= nums[i] / j;
                        }
                        cnt_suf[nums[i] / j] += c;
                        cnt_num[i][nums[i] / j] += c;
                    }
                }
            }
        }
        int cnt_both = 0;
        for (const auto& [j, c] : cnt_pre) {
            if (c > 0 && cnt_suf[j] > 0) {
                ++cnt_both;
            }
        }
        if (cnt_both == 0) {
            return 0;
        }
        for (int i = 1; i < n - 1; ++i) {
            for (const auto& [j, c] : cnt_num[i]) {
                if (cnt_pre[j] > 0 && cnt_suf[j] > 0) {
                    cnt_pre[j] += c;
                    cnt_suf[j] -= c;
                    if (cnt_pre[j] == 0 || cnt_suf[j] == 0) {
                        --cnt_both;
                    }
                } else {
                    cnt_pre[j] += c;
                    cnt_suf[j] -= c;
                    if (cnt_pre[j] > 0 && cnt_suf[j] > 0) {
                        ++cnt_both;
                    }
                }
            }
            if (cnt_both == 0) {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{4,7,15,8,3,5};
    cout << Solution().findValidSplit(v) << endl;
    return 0;
}
