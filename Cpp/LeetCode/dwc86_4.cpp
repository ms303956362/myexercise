#include "usual.h"

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size(), l = 1, h = n;
        auto check = [&](int k) -> bool {
            deque<long long> q;
            long long sum = 0;
            for (int i = 0; i < k; ++i) {
                while (!q.empty() && q.back() < chargeTimes[i]) {
                    q.pop_back();
                }
                q.push_back(chargeTimes[i]);
                sum += runningCosts[i];
            }
            if (k * sum + q.front() <= budget) {
                return true;
            }
            for (int i = k; i < n; ++i) {
                if (!q.empty() && q.front() == chargeTimes[i - k]) {
                    q.pop_front();
                }
                while (!q.empty() && q.back() < chargeTimes[i]) {
                    q.pop_back();
                }
                q.push_back(chargeTimes[i]);
                sum -= runningCosts[i - k];
                sum += runningCosts[i];
                if (k * sum + q.front() <= budget) {
                    return true;
                }
            }
            return false;
        };
        while (l <= h) {
            int m = (l + h) / 2;
            if (check(m)) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return h;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
