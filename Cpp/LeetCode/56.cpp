#include "usual.h"
struct Interval {
    int a;
    int b;
    Interval(int x = 0, int y = 0) : a(x), b(y) {}
};

bool operator<(const Interval& i1, const Interval& i2) {
    return i1.a < i2.a || (i1.a == i2.a && i1.b < i2.b);
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        list<Interval> a;
        for (auto i = 0; i != n; ++i) {
            a.push_back(Interval(intervals[i][0], intervals[i][1]));
        }
        a.sort();
        for (auto p1 = a.begin(), p2 = ++a.begin(); p2 != a.end();) {
            if (p2->a <= p1->b) {
                auto tmp = ++p2;
                --p2;
                Interval v(min(p1->a, p2->a), max(p1->b, p2->b));
                a.erase(p1);
                a.erase(p2);
                p2 = tmp;
                p1 = a.insert(p2, v);
            } else {
                ++p1;
                ++p2;
            }
        }
        vector<vector<int>> res;
        for (const auto& i : a) {
            res.push_back(vector<int>{i.a, i.b});
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v{{0,0},{1,2},{5,5},{2,4},{3,3},{5,6},{5,6},{4,6},{0,0},{1,2},{0,2},{4,5}}, 
                        v2{{0,2},{3,3},{2,4}};
    Solution().merge(v);
    return 0;
}
