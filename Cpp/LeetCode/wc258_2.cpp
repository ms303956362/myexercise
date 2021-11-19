#include "usual.h"

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long> cnt;
        for (const auto& r : rectangles) {
            if (cnt.count((double)r[0] / (double)r[1]))
                ++cnt[(double)r[0] / (double)r[1]];
            else
                cnt[(double)r[0] / (double)r[1]] = 1;
        }
        long long ans = 0;
        for (const auto& [r, c] : cnt) {
            ans += (c - 1) * c / 2;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
