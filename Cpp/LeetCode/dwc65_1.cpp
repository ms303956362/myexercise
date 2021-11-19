#include "usual.h"

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        auto check = [&](int k)
        {
            int p = pills;
            multiset<int> s(workers.rbegin(), workers.rbegin() + k);
            for (int i = k - 1; i >= 0; --i)
            {
                auto p1 = s.lower_bound(tasks[i]);
                if (p1 != s.end()) {
                    s.erase(p1);
                } else if (p > 0) {
                    auto p2 = s.lower_bound(tasks[i] - strength);
                    if (p2 != s.end()) {
                        s.erase(p2);
                        --p;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            return true;
        };
        int l = 0, h = min(tasks.size(), workers.size());
        while (l <= h) {
            int m = (l + h) / 2;
            if (check(m))
                l = m + 1;
            else
                h = m - 1;
        }
        return l;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
