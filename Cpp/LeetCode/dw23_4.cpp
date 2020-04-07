#include "usual.h"

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int sum = 0, ans = 0;
        for (int i = satisfaction.size() - 1; i >= 0; --i) {
            sum += satisfaction[i];
            if (sum > 0) {
                ans += sum;
            } else {
                break;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{-2,5,-1,0,3,-3};
    cout << Solution().maxSatisfaction(v) << endl;
    return 0;
}
