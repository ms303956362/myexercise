#include "usual.h"

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> left(n + 1, 0), right(n + 1, 0);
        for (int i = 1; i != n + 1; ++i) {
            left[i] = left[i - 1] + cardPoints[i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            right[i] = right[i + 1] + cardPoints[i];
        }
        int max_res = 0;
        for (int i = 0; i != k + 1; ++i) {
            if (left[i] + right[n - k + i] > max_res)
                max_res = left[i] + right[n - k + i];
        }
        return max_res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{1, 2, 3, 4, 5, 6, 1};
    Solution().maxScore(v, 3);
    return 0;
}
