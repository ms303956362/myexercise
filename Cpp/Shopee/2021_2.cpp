#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

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

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), pre(n + 1);
    set<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
        s.insert(pre[i] - k * i);
    }
    s.insert(pre[n] - k * n);
    int j = 0;
    unordered_map<int, int> idx;
    for (const auto& num : s) {
        idx[num] = j;
        ++j;
    }
    BIT t(s.size());
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += t.query(idx[pre[i] - k * i]);
        t.update(idx[pre[i] - k * i], 1);
    }
    cout << ans << endl;
    return 0;
}

