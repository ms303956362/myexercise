#include "usual.h"

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> f(n + 1, 0);
        int sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            sum += stoneValue[i];
            int min_f = 1e9;
            for (int j = 1; i + j < n + 1 && j <= 3; ++j) {
                if (f[i+j] < min_f)
                    min_f = f[i+j];
            }
            f[i] = sum - min_f;
        }
        if (f[0] > sum - f[0]) {
            return "Alice";
        } else if (f[0] < sum - f[0])
            return "Bob";
        else
            return "Tie";
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{1,2,3,7};
    cout << Solution().stoneGameIII(v) << endl;
    return 0;
}
