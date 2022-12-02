#include "usual.h"

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        multiset<pair<int, int>> s;
        for (const auto& i : intervals) {
            s.emplace(i[0], i[1]);
        }
        int ans = 0;
        while (!s.empty()) {
            auto p = s.begin();
            auto pr = *p;
            s.erase(p);
            while (!s.empty()) {
                auto q = s.lower_bound(make_pair(pr.second + 1, 0));
                if (q == s.end()) {
                    break;
                }
                auto qr = *q;
                s.erase(q);
                p = q;
                pr = qr;
            }
            ++ans;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
