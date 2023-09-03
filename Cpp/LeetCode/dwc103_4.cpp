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
    long long countOperationsToEmptyArray(vector<int>& nums) {
        long long n = nums.size();
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> q;
        for (int i = 0; i < n; ++i) {
            q.emplace(nums[i], i);
        }
        BIT t(n);
        long long i = 0, ans = 0;
        while (!q.empty()) {
            auto [_, j] = q.top();
            q.pop();
            // cout << i << " " << j << endl;
            if (j > i) {
                ans += j - i + 1 - (t.query(j) - (i == 0 ? 0 : t.query(i - 1)));
            } else if (i < j) {
                ans += n - i + j + 1 - (t.query(n - 1) - t.query(i - 1) + t.query(j));
            } else {
                ++ans;
            }
            // cout << ans << endl;
            t.update(j, 1);
            i = (j + 1) % n;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> a{3,4,-1};
    cout << Solution().countOperationsToEmptyArray(a) << endl;
    return 0;
}
