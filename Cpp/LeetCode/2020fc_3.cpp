#include "usual.h"

typedef unsigned long long ull;

class Solution {
public:
    int minimumOperations(string leaves) {
        list<int> l;
        multimap<int, ull> mp;
        unordered_set<ull> s;
        int ans = 0, n = leaves.size();
        if (leaves[0] == 'y') {
            leaves[0] = 'r';
            ++ans;
        }
        if (leaves[n - 1] == 'y') {
            leaves[n - 1] = 'r';
            ++ans;
        }
        int cnt = 1;
        char c = 'r';
        bool first = true;
        for (int i = 1; i != n; ++i) {
            if (leaves[i] != c) {
                l.push_back(cnt);
                s.insert((ull)&l.back());
                if (first)
                    first = false;
                else
                    mp.emplace(cnt, (ull)&l.back());
                cnt = 1;
                c = leaves[i];
            } else {
                ++cnt;
            }
        }
        l.push_back(cnt);
        s.insert((ull)&l.back());
        if (l.size() == 1)
            return 1;
        if (l.size() == 3)
            return 0;
        while (l.size() > 3) {
            list<int>::iterator p = *(list<int>::iterator*)(mp.begin()->second);
            mp.erase(mp.begin());
            if (s.count((ull)&p) == 0) {
                continue;
            }
            ans += *p;
            auto pn = next(p), pp = prev(p);
            *p += *pn + *pp;
            l.erase(pn);
            s.erase((ull)&pn);
            l.erase(pp);
            s.erase((ull)&pp);
            mp.emplace(*p, (ull)&p);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution().minimumOperations("rrryyyrryyyrr");
    return 0;
}
