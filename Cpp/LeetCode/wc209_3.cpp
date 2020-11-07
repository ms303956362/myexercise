#include "usual.h"

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int n = points.size();
        int must = 0;
        vector<double> a;
        for (int i = 0; i != n; ++i) {
            if (points[i][1] == location[1] && points[i][0] == location[0]) {
                ++must;
                continue;
            }
            double ag = atan2(points[i][1] - location[1], points[i][0] - location[0]);
            ag = ag * 360 / (2 * 3.14159265358979323846);
            a.push_back(ag);
        }
        n = a.size();
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0, j = 1; i < n; j = (j + 1) % n) {
            while (i < n) {
                double diff = a[j] - a[i];
                if (diff < 0)
                    diff += 360;
                if (diff <= angle)
                    break;
                ++i;
            }
            int len = j - i + 1;
            if (len <= 0)
                len += n;
            ans = max(ans, len);
            if (ans == n)
                break;
        }
        return ans + must;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> p{{ 2, 1 }, { 2, 2 }, { 3, 3 }};
    int a = 90;
    vector<int> l{1, 1};
    Solution().visiblePoints(p, a, l);
    return 0;
}
