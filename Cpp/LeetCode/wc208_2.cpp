#include "usual.h"

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int i = 0, n = customers.size();
        int on = 0, wait = 0;
        int step = 0, maxpro = INT_MIN, pro = 0, ans = -1;
        while (i < n || wait > 0) {
            if (i < n) {
                wait += customers[i];
                ++i;
            }
            int goOn = min(wait, 4);
            wait -= goOn;
            on += goOn;
            ++step;
            pro = on * boardingCost - step * runningCost;
            if (pro > maxpro) {
                maxpro = pro;
                if (maxpro > 0)
                    ans = step;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{3,4,0,5,1};
    int b = 1, r = 92;
    cout << Solution().minOperationsMaxProfit(v, b, r) << endl;
    return 0;
}
