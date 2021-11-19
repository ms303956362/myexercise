#include "usual.h"

class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size(), max_elem = *max_element(nums.begin(), nums.end());
        set<int> s;
        vector<vector<int>> t(n, vector<int>());
        vector<int> ans(n, 1);
        vector<bool> vst(n, false), has(max_elem + 2, false);
        for (int i = 1; i < n; ++i) {
            t[parents[i]].push_back(i);
        }
        int u1 = dfs1(0, nums, t);
        int i = 2;
        for (int u = u1; u != -1; u = parents[u]) {
            dfs2(u, t, nums, vst, has);
            for (; i <= max_elem + 1; ++i) {
                if (!has[i])
                    break;
            }
            ans[u] = i;
        }
        return ans;
    }

    int dfs1(int u, vector<int>& nums, vector<vector<int>>& t) {
        if (nums[u] == 1)
            return u;
        for (const auto& v : t[u]) {
            int ret = -1;
            if ((ret =  dfs1(v, nums, t)) != -1)
                return ret;
        }
        return -1;
    }

    void dfs2(int u, vector<vector<int>>& t, vector<int>& nums, vector<bool>& vst, vector<bool>& has) {
        vst[u] = true;
        has[nums[u]] = true;
        for (const auto& v : t[u]) {
            if (!vst[v])
                dfs2(v, t, nums, vst, has);
        }
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
