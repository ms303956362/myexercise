#include "usual.h"

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<int> ans(2, 0);
        int max_sum = 0;
        for (int i = 0; i <= 100; ++i) {
            for (int j = 0; j <= 100; ++j) {
                int sum = 0;
                for (const auto& t : towers) {
                    double d = sqrt((t[0] - i) * (t[0] - i) + (t[1] - j) * (t[1] - j));
                    if (d <= radius)
                        sum += (int)(t[2] / (1 + d));
                }
                if (sum > max_sum) {
                    max_sum = sum;
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
