#include "usual.h"

class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int n = temperatureA.size();
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            while (j < n && dir(temperatureA[j], temperatureA[j - 1]) == dir(temperatureB[j], temperatureB[j - 1])) {
                ++j;
            }
            cout << i << " " << j << endl;
            ans = max(ans, j - i);
        }
        return ans;
    }

    int dir(int a, int b) {
        if (a > b) {
            return 1;
        } else if (a == b) {
            return 0;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
