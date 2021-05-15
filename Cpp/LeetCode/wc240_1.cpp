#include "usual.h"

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int ans = 0, pop = 0;
        for (int year = 1950; year <= 2050; ++year) {
            int cnt = 0;
            for (const auto& p : logs) {
                if (p[0] <= year && year < p[1])
                    ++cnt;
            }
            if (cnt > pop) {
                pop = cnt;
                ans = year;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
