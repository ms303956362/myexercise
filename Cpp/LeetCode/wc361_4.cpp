#include "usual.h"

class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<int>> v(n + 1), w(n + 1), fa(n + 1, vector<int>(31)), cnt(n + 1, vector<int>(27));
        vector<int> dep(n + 1), ct(27);
        // dfs，用来为 lca 算法做准备。接受两个参数：dfs 起始节点和它的父亲节点。
        function<void(int, int)> dfs = [&](int root, int fno) {
            // 初始化：第 2^0 = 1 个祖先就是它的父亲节点，dep 也比父亲节点多 1。
            fa[root][0] = fno;
            dep[root] = dep[fa[root][0]] + 1;
            // 初始化：其他的祖先节点：第 2^i 的祖先节点是第 2^(i-1) 的祖先节点的第
            // 2^(i-1) 的祖先节点。
            for (int i = 1; i < 31; ++i) {
                fa[root][i] = fa[fa[root][i - 1]][i - 1];
            }
            cnt[root] = ct;
            // 遍历子节点来进行 dfs。
            int sz = v[root].size();
            for (int i = 0; i < sz; ++i) {
                if (v[root][i] == fno) {
                    continue;
                }
                ++ct[w[root][i]];
                dfs(v[root][i], root);
                --ct[w[root][i]];
            }
        };
        // lca。用倍增算法算取 x 和 y 的 lca 节点。
        function<int(int, int)> lca = [&](int x, int y) {
            // 令 y 比 x 深。
            if (dep[x] > dep[y]) {
                swap(x, y);
            }
            // 令 y 和 x 在一个深度。
            int tmp = dep[y] - dep[x];
            for (int j = 0; tmp; ++j, tmp >>= 1) {
                if (tmp & 1) {
                    y = fa[y][j];
                }
            }
            // 如果这个时候 y = x，那么 x，y 就都是它们自己的祖先。
            if (y == x) {
                return y;
            }
            // 不然的话，找到第一个不是它们祖先的两个点。
            for (int j = 30; j >= 0 && y != x; --j) {
                x = fa[x][j];
                y = fa[y][j];
            }
            // 返回结果。
            return y;
        };
        for (auto e : edges) {
            int a = e[0], b = e[1], c = e[2];
            ++a;
            ++b;
            v[a].push_back(b);
            v[b].push_back(a);
            w[a].push_back(c);
            w[b].push_back(c);
        }
        dfs(1, 0);
        vector<int> ans;
        for (auto q : queries) {
            int a = q[0] + 1, b = q[1] + 1;
            auto ca = cnt[a], cb = cnt[b], cf = cnt[lca(a, b)];
            int total = 0;
            for (int i = 1; i <= 26; ++i) {
                int c = ca[i] + cb[i] - 2 * cf[i];
                total += c;
            }
            int mn = total;
            for (int i = 1; i <= 26; ++i) {
                int c = ca[i] + cb[i] - 2 * cf[i];
                mn = min(mn, total - c);
            }
            ans.push_back(mn);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << "Hello " << s << endl;
    int n = 8;
    vector<vector<int>> edges{{1,2,6},{1,3,4},{2,4,6},{2,5,3},{3,6,6},{3,0,8},{7,0,2}};
    vector<vector<int>> queries{{4,6},{0,4},{6,5},{7,4}};
    Solution().minOperationsQueries(n, edges, queries);
    return 0;
}
