#include "usual.h"

class BIT {
    int n;
    vector<int> tree;
public:
    BIT(int _n) : n(_n + 1), tree(_n + 1, 0) {}
    BIT(const vector<int>& a) : n(a.size() + 1), tree(a.size() + 1, 0) {
        for (int i = 1; i < n; ++i) {
            update(i - 1, a[i - 1]);
        }
    }

    inline int lowBit(int i) { return i & (-i); }

    void update(int i, int delta) {
        ++i;
        while (i < n) {
            tree[i] += delta;
            i += lowBit(i);
        }
    }

    int query(int i) {
        ++i;
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= lowBit(i);
        }
        return sum;
    }

};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> idx(n);
        for (int i = 0; i < n; ++i) {
            idx[nums2[i]] = i;
        }
        BIT t(n);
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = idx[nums1[i]];
            long long k = t.query(j);
            t.update(j, 1);
            ans += k * (n - i - 1 - (j - k));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
