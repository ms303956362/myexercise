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
    int reversePairs(vector<int>& nums) {
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a(37);
    for (int i = 0; i != 37; ++i) {
        a[i] = i + 1;
    }
    BIT bit(a);
    cout << "Before modifying: " << bit.query(0) << " " << bit.query(36) << endl;
    bit.update(0, 2);
    cout << "After modifying: " << bit.query(0) << " " << bit.query(36) << endl;
    return 0;
}
