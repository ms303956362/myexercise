#include "usual.h"

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, h = *max_element(time.begin(), time.end()) * totalTrips;
        while (l <= h) {
            long long m = (l + h) / 2;
            long long cnt = 0;
            for (const auto& t : time) {
                cnt += m / t;
            }
            if (cnt >= totalTrips) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> time{1, 2, 3};
    Solution().minimumTime(time, 5);
    return 0;
}
