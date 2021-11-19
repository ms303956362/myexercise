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
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DSU s(n);
        unordered_set<int> st;
        for (const auto& r : restrictions) {
            st.insert(r[0]);
            st.insert(r[1]);
        }
        vector<int> res_users(st.begin(), st.end());
        vector<int> p(n);
        vector<bool> ans;
        for (const auto& r : requests) {
            int px = s.find(r[0]), py = s.find(r[1]);
            for (const auto& user : res_users)
                p[user] = s.find(user);
            bool ok = true;
            for (const auto& r : restrictions) {
                if (p[r[0]] == px && p[r[1]] == py || p[r[1]] == px && p[r[0]] == py) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                s.unite(r[0], r[1]);
            ans.push_back(ok);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
