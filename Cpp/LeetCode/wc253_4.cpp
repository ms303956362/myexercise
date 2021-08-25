#include "usual.h"

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size(), len = 1;
        vector<int> d, ans;
        ans.push_back(1);
        d.push_back(obstacles[0]);
        for (int i = 1; i < n; ++i) {
            if (obstacles[i] >= d.back()) {
                d.push_back(obstacles[i]);
                ans.push_back(d.size());
            }
            else {
                int m = upper_bound(d.begin(), d.end(), obstacles[i]) - d.begin();
                d[m] = obstacles[i];
                ans.push_back(m + 1);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
