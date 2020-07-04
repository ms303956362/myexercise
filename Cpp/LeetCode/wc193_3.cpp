#include "usual.h"

struct Pair {
    int i;
    int n;
    Pair(int idx, int num) : i(idx), n(num) {}
};

bool operator<(const Pair &p1, const Pair &p2) { return p1.n < p2.n; }

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        priority_queue<Pair> q;
        int n = bloomDay.size();
        for (int i = 0; i != n; ++i) {
            q.push(Pair(i, bloomDay[i]));
        }
        set<int> s;
        s.insert(0);
        s.insert(n - 1);
        int ans = -1;
        while (true) {
            Pair p = q.top();
            q.pop();
            int idx = p.i;
            auto it = s.lower_bound(idx);
            auto itn = it;
            ++itn;
            if ((idx - *it) / k + (*itn - idx) / k < min(m, (*itn - *it) / k)) {
                ans = idx;
                break;
            }
            s.insert(idx);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{1, 10, 3, 10, 2};
    int m = 3, k = 1;
    Solution().minDays(v, m, k);
    return 0;
}
