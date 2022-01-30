#include "usual.h"

class DSU {
public:
    int n;
    vector<int> p;  // 祖先
    vector<int> r;  // 树高
    vector<int> cnt;
    int size;

    DSU(int _n) : n(_n), p(_n), r(_n, 0), size(_n), cnt(_n, 1) {
        for (int i = 0; i != n; ++i) {
            p[i] = i;
        }
    }

    int find(int x) {
        if (p[x] == x)
            return x;
        return p[x] = find(p[x]); // x的祖先直接设为根节点，路径压缩
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py)
            return false;
        if (r[px] < r[py]) {  // 低树的作为高树的子树，高树高度不变
            p[px] = py;
            cnt[py] += cnt[px];
        } else {
            p[py] = px;
            if (r[px] == r[py]) {   // 树高相等，默认px为py祖先，且需px高度加1
                r[px]++;
            }
            cnt[px] += cnt[py];
        }
        --size;
        return true;
    }

    int count(int i) {
        return cnt[i];
    }

    int sz() {
        return size;
    }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        DSU s(n);
        unordered_map<int, int> idx;
        vector<int> masks(n);
        for (int i = 0; i < n; ++i) {
            for (const auto& c : words[i]) {
                masks[i] |= (1 << (c - 'a'));
            }
            if (idx.count(masks[i])) {
                s.unite(i, idx[masks[i]]);
            }
            idx[masks[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                int mask = masks[i] ^ (1 << j);
                if (idx.count(mask)) {
                    s.unite(i, idx[mask]);
                }
            }
            for (int j = 0; j < 26; ++j) {
                if ((masks[i] & (1 << j)) != 0) {
                    int mask = masks[i] & ~(1 << j);
                    for (int k = 0; k < 26; ++k) {
                        if (k != j && (mask & (1 << k)) == 0) {
                            int mask2 =  mask | (1 << k);
                            if (idx.count(mask2)) {
                                s.unite(i, idx[mask2]);
                            }
                        }
                    }
                }
            }
        }
        vector<int> ans(2);
        ans[0] = s.sz();
        for (int i = 0; i < n; ++i) {
            if (i == s.p[i]) {
                ans[1] = max(ans[1], s.count(i));
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
