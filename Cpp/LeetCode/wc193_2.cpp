#include "usual.h"

struct Pair {
    int i;
    int cnt;
    Pair (int ii, int cc) : i(ii), cnt(cc) {}
};

bool operator<(const Pair &p1, const Pair &p2) { return p1.cnt > p2.cnt; }

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        for (auto i : arr) {
            auto p = cnt.find(i);
            if (p != cnt.end())
                ++p->second;
            else
                cnt[i] = 1;
        }
        priority_queue<Pair> q;
        int ans = 0;
        for (auto [i, c] : cnt) {
            q.push(Pair(i, c));
            ++ans;
        }
        while (!q.empty() && k >= q.top().cnt) {
            k -= q.top().cnt;
            --ans;
            q.pop();
        }
        return ans;
    }
};