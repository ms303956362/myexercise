#include "usual.h"

class SegTreeNode {
public:
    int left, right;
    int mn;
};

class SegTree {
    vector<SegTreeNode> rt;
    
    int tl(int x) { return x * 2; }
    int tr(int x) { return x * 2 + 1; }

    void pushup(int x) {
        rt[x].mn = min(rt[tl(x)].mn, rt[tr(x)].mn);
    }

public:
    SegTree(int n): rt(4 * (n + 2)) {
        build(1, 1, n);
    }

    void build(int x,int L,int R) {
        rt[x].left = L; rt[x].right = R;
        if (L == R) {
            rt[x].mn = 0x3f3f3f3f;
            return;
        }
        int mid = (L + R) >> 1;
        build(tl(x), L, mid); build(tr(x), mid + 1, R);
        pushup(x);
    }

    void upd(int x, int pos, int val) {
        if (rt[x].left == rt[x].right) {
            rt[x].mn = val;
            return;
        }
        int mid = (rt[x].left + rt[x].right) >> 1;
        if (pos <= mid)upd(tl(x), pos, val);
        else upd(tr(x), pos, val);
        pushup(x);
    }

    int fmin(int x, int L, int R) {
        if (L == rt[x].left&&R == rt[x].right) {
            return rt[x].mn;
        }
        int mid = (rt[x].left + rt[x].right) >> 1;
        int ret = 0x3f3f3f3f;
        if (R <= mid) return min(ret, fmin(tl(x), L, R));
        else if (L > mid) return min(ret, fmin(tr(x), L, R));
        else return min(fmin(tl(x), L, mid), fmin(tr(x), mid + 1, R));
    }
};

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<SegTree> rowt(m, SegTree(n)), colt(n, SegTree(m));
        int ans = 0x3f3f3f3f;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1) {
                    rowt[i].upd(1, n, 0);
                    colt[j].upd(1, m, 0);
                    continue;
                }
                int step = 0x3f3f3f3f;
                if (i < m - 1 && grid[i][j] > 0) {
                    step = min(step, colt[j].fmin(1, i + 2, min(i + grid[i][j] + 1, m)));
                }
                if (j < n - 1 && grid[i][j] > 0) {
                    step = min(step, rowt[i].fmin(1, j + 2, min(j + grid[i][j] + 1, n)));
                }
                if (i == 0 && j == 0) {
                    ans = step;
                }
                if (step < 0x3f3f3f3f) {
                    rowt[i].upd(1, j + 1, step);
                    colt[j].upd(1, i + 1, step);
                }
            }
        }
        return ans < 0x3f3f3f3f ? ans : -1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
