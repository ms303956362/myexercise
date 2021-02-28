#include "usual.h"

class DSU {
    int n;
    vector<int> p;

public:
    int cnt;

    DSU(int _n) : n(_n), p(_n), cnt(_n) {
        for (int i = 0; i != _n; ++i)
            p[i] = i;
    }

    int find(int x) {
        return x == p[x] ? x : (p[x] = find(p[x]));
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py)
            return false;
        p[px] = py;
        --cnt;
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int j = 0; j != m; ++j) {
            edges[j].push_back(j);
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& v1, const vector<int>& v2) { return v1[2] < v2[2]; });
        vector<int> used(m, 0);
        int leastSum = krusal(edges, used, m, n);
        vector<vector<int>> ans(2);
        for (int j = 0 ;j != m; ++j) {
            if (krusal(edges, used, j, n) > leastSum) {
                ans[0].push_back(edges[j][3]);
                used[j] = 2;
            }
        }
        for (int j = 0; j != m; ++j) {
            if (used[j] == 1)
                ans[1].push_back(edges[j][3]);
        }
        return ans;
    }

    int krusal(const vector<vector<int>>& edges, vector<int>& used, int j, int n) {
        int m = edges.size();
        DSU s(n);
        int sum = 0;
        for (int i = 0; i != m; ++i) {
            if (i == j)
                continue;
            const auto& e = edges[i];
            if (s.unite(e[0], e[1])) {
                sum += e[2];
                if (used[i] == 0)
                    used[i] = 1;
            }
            if (s.cnt == 1)
                break;
        }
        return s.cnt > 1 ? INT_MAX : sum;
    }
};

int main(int argc, char const *argv[])
{
    int n = 6;
    vector<vector<int>> edges{{ 0, 1, 1 }, { 1, 2, 1 }, { 0, 2, 1 }, { 2, 3, 4 }, { 3, 4, 2 }, { 3, 5, 2 }, { 4, 5, 2 }};
    Solution().findCriticalAndPseudoCriticalEdges(n, edges);
    return 0;
}
