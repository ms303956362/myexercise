#include "usual.h"

class Solution {
public:
    int circleGame(vector<vector<int>>& toys, vector<vector<int>>& circles, int r) {
        unordered_map<int, unordered_set<int>> a;
        for (const auto& v : circles) {
            a[v[0]].insert(v[1]);
        }
        int ans = 0;
        for (const auto& v : toys) { // 遍历玩具
            long long xc = v[0], yc = v[1], rt = v[2];
            if (rt > r)
                continue;
            for (long long x = xc - r; x <= xc + r; ++x) {
                bool ok = false;
                for (long long y = yc - r; y <= yc + r; ++y) { // 遍历附近圆圈
                    if (a.count(x) && a[x].count(y) && (x - xc) * (x - xc) + (y - yc) * (y - yc) <= (r - rt) * (r - rt)) { // 在圆圈内
                        ++ans;
                        ok = true;
                        break;
                    }
                }
                if (ok)
                    break;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
