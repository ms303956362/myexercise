#include "usual.h"

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> times(n + 1, 0);
        for (int i = 0; i != rounds.size() - 1; ++i) {
            for (int j = rounds[i]; j != rounds[i + 1]; j = j % n + 1) {
                ++times[j];
            }
        }
        ++times[*rounds.rbegin()];
        int maxt = INT_MIN;
        for (int t : times)
            maxt = max(maxt, t);
        vector<int> res;
        for (int i = 1; i <= n; ++i)
            if (times[i] == maxt)
                res.push_back(i);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int n = 4;
    vector<int> r{1, 3, 1, 2};
    Solution().mostVisited(n, r);
    return 0;
}
