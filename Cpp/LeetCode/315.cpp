#include "usual.h"

class TreeArray {
    int n;
    vector<int> c;

public:
    TreeArray(int nn) : n(nn), c(nn + 1, 0) {}

    int lowBit(int i) { return i&(-i); }

    void update(int i, int k=1) {
        while (i <= n) {
            c[i] += k;
            i += lowBit(i);
        }
    }

    int query(int i) {
        int s = 0;
        while (i > 0) {
            s += c[i];
            i -= lowBit(i);
        }
        return s;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> idx;
        vector<int> a(nums.begin(), nums.end()), ans(n, 0);
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        TreeArray t(a.size());
        for (int i = 0; i != a.size(); ++i) {
            idx[a[i]] = i + 1;
        }
        t.update(idx[nums[n - 1]]);
        for (int i = n - 2; i >= 0; --i) {
            int j = idx[nums[i]]; // the index of nums[i] in a
            ans[i] = t.query(j - 1);
            t.update(j);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{5, 6, 2, 6, 1};
    Solution().countSmaller(v);
    return 0;
}
