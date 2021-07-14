#include "usual.h"

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 0, h = 1e8, n = dist.size();
        while (l <= h) {
            int t1 = 0;
            double t = 0;
            int m = (l + h) / 2;
            for (int i = 0; i < n - 1; ++i) {
                t1 += (dist[i] + m - 1) / m;
            }
            t = (double)t1 + (double)dist[n - 1] / (double)m;
            if (t <= hour)
                h = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
