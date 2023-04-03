#include "usual.h"

struct dsu {
  vector<size_t> pa, size;

  explicit dsu(size_t size_) : pa(size_ * 2), size(size_ * 2, 1) {
    iota(pa.begin(), pa.begin() + size_, size_);
    iota(pa.begin() + size_, pa.end(), size_);
  }

  size_t find(size_t x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }

  void unite(size_t x, size_t y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    pa[y] = x;
    size[x] += size[y];
  }

  void erase(size_t x) {
    --size[find(x)];
    pa[x] = x;
  }
};


class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dsu d(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                if (i + 1 < m && grid[i + 1][j] == 1) {
                    d.unite(i * n + j, (i + 1) * n + j);
                }
                if (j + 1 < n && grid[i][j + 1] == 1) {
                    d.unite(i * n + j, i * n + j + 1);
                }
            }
        }
        vector<pair<int, int>> dir{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 || (i == 0 && j == 0) || (i == m - 1 && j == n - 1)) {
                    continue;
                }
                d.erase(i * n + j);
                if (d.find(0) != d.find(m * n - 1)) {
                    ++cnt;
                }
                for (const auto& [dx, dy] : dir) {
                    int x = i + dx, y = j + dy;
                    if (0 <= x && x < m && 0 <= y && y < n) {
                        d.unite(i * n + j, x * n + y);
                    }
                }
            }
        }
        return cnt > 1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
