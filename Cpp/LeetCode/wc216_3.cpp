#include "usual.h"

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> postodd(n, 0), posteven(n, 0);
        if ((n - 1) & 1)
            postodd[n - 1] = nums[n - 1];
        else
            posteven[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (i & 1) {
                postodd[i] = postodd[i + 1] + nums[i];
                posteven[i] = posteven[i + 1];
            } else {
                posteven[i] = posteven[i + 1] + nums[i];
                postodd[i] = postodd[i + 1];
            }
        }
        int ans = 0;
        int preodd = 0, preeven = 0;
        if (postodd[0] - postodd[n - 1] == posteven[0] - posteven[n - 1])
            ++ans;
        for (int i = n - 2; i >= 0; --i) {
            preodd = postodd[0] - postodd[i];
            preeven = posteven[0] - posteven[i];
            preodd += posteven[i + 1];
            preeven += postodd[i + 1];
            ans += (preodd == preeven);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{1, 1, 1};
    cout << Solution().waysToMakeFair(v) << endl;
    return 0;
}
