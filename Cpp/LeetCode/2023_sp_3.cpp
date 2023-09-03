#include "usual.h"

class Solution {
public:
    int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
        int n = forceField.size();
        auto intersection = [](double a1, double a2, double b1, double b2) {
            return make_pair(max(a1, b1), min(a2, b2));
        };
        auto count_num = [&](double x, double y) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                double x1 = forceField[i][0] - (double)forceField[i][2] / 2, x2 = forceField[i][0] + (double)forceField[i][2] / 2;
                double y1 = forceField[i][1] - (double)forceField[i][2] / 2, y2 = forceField[i][1] + (double)forceField[i][2] / 2;
                if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
                    ++cnt;
                }
            }
            return cnt;
        };
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            double x1 = forceField[i][0] - (double)forceField[i][2] / 2, x2 = forceField[i][0] + (double)forceField[i][2] / 2;
            double y1 = forceField[i][1] - (double)forceField[i][2] / 2, y2 = forceField[i][1] + (double)forceField[i][2] / 2;
            for (int j = i + 1; j < n; ++j) {
                double x3 = forceField[j][0] - (double)forceField[j][2] / 2, x4 = forceField[j][0] + (double)forceField[j][2] / 2;
                double y3 = forceField[j][1] - (double)forceField[j][2] / 2, y4 = forceField[j][1] + (double)forceField[j][2] / 2;
                auto [a1, a2] = intersection(x1, x2, x3, x4);
                if (a1 > a2) {
                    continue;
                }
                auto [b1, b2] = intersection(y1, y2, y3, y4);
                if (b1 > b2) {
                    continue;
                }
                ans = max({ans, count_num(a1, b1), count_num(a1, b2), count_num(a2, b1), count_num(a2, b2)});
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
