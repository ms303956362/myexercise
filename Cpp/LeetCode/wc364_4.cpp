#include "usual.h"

const int N = 1e5 + 5;
bool is_prime[N], prime[N];
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

bool is_init = false;

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        if (!is_init) {
            Eratosthenes(1e5 + 3);
            is_init = true;
        }
        vector<vector<int>> g(n + 1);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<long long> cnt(n + 1);
        function<void(int, int)> dfs1 = [&](int u, int f) {
            long long total = 0;
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                dfs1(v, u);
                total += cnt[v];
            }
            if (!is_prime[u]) {
                cnt[u] = total + 1;
            }
        };
        dfs1(1, -1);
        long long ans = 0;
        function<void(int, int)> dfs2 = [&](int u, int f) {
            if (is_prime[u]) {
                long long total1 = 0, total2 = 0;
                for (const auto& v : g[u]) {
                    total1 += cnt[v];
                    total2 += cnt[v] * cnt[v];
                }
                ans += (total1 * total1 - total2) / 2 + total1;
            }
            for (const auto& v : g[u]) {
                if (v == f) {
                    continue;
                }
                long long tmp1 = cnt[u], tmp2 = cnt[v];
                if (!is_prime[u] && !is_prime[v]) {
                    cnt[u] -= cnt[v];
                    cnt[v] = tmp1;
                }
                dfs2(v, u);
                if (!is_prime[u] && !is_prime[v]) {
                    cnt[u] = tmp1;
                    cnt[v] = tmp2;
                }
            }
        };
        dfs2(1, -1);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n = 5;
    vector<vector<int>> edges{{1,2},{1,3},{2,4},{2,5}};
    Solution().countPaths(n, edges);
    return 0;
}
