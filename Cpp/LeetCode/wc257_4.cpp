#include "usual.h"

class DSU {
    int n;
    vector<int> p;  // 祖先
    vector<int> r;  // 树高 
public:
    DSU(int _n) : n(_n), p(_n), r(_n, 0) {
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
        if (r[px] < r[py])  // 低树的作为高树的子树，高树高度不变
            p[px] = py;
        else {
            p[py] = px;
            if (r[px] == r[py])   // 树高相等，默认px为py祖先，且需px高度加1
                r[px]++;
        }
        return true;
    }
};

class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isprime(1e5 + 5, true);
        for (int i = 2; i < 1e5 + 5; ++i) {
            if (isprime[i]) {
                for (int j = i; j * i < 1e5 + 5; ++j) {
                    isprime[j * i] = false;
                }
            }
        }
        DSU uf(n);
        unordered_map<int, unordered_set<int>> s;
        for (int i = 0; i < n; ++i) {
            decompose(i, nums[i], s, isprime);
        }
        for (const auto& [num, m] : s) {
            int bidx = *m.begin();
            for (const auto& idx : m) {
                uf.unite(bidx, idx);
            }
        }
        unordered_map<int, vector<pair<int, int>>> mp;
        vector<int> a(nums);
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            int p = uf.find(i);
            mp[p].emplace_back(i, nums[i]);
        }
        for (auto& [p, v] : mp) {
            vector<int> aa, bb;
            for (const auto& [idx, num] : v) {
                aa.push_back(idx);
                bb.push_back(num);
            }
            sort(bb.begin(), bb.end());
            sort(aa.begin(), aa.end());
            int m = aa.size();
            for (int i = 0; i < m; ++i) {
                if (a[aa[i]] !=  bb[i])
                    return false;
            }
        }
        return true;
    }

    void decompose(int idx, int num, unordered_map<int, unordered_set<int>>& s, vector<bool>& isprime) {
        if (isprime[num])
            s[num].insert(idx);
        for (int i = 2; i <= sqrt(num); ++i) {
            if (!isprime[i])
                continue;
            if (num % i == 0) {
                s[i].insert(idx);
                s[num / i].insert(idx);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{7, 21, 3};
    Solution().gcdSort(v);
    return 0;
}
