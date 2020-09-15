#include "usual.h"

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), i = 0, j = n - 1, k = n - 1;
        for (i = 0; i != n - 1; ++i) {
            if (arr[i] > arr[i + 1])
                break;
        }
        for (j = n - 1; j > 0; --j) {
            if (arr[j] < arr[j - 1])
                break;
        }
        if (j <= i)
            return 0;
        int ans = j - i - 1, i0 = i;
        for (k = n - 1; k >= j; --k) {
            if (arr[k] < arr[i])
                break;
        }
        int add = k - j + 1, newadd = 0, ans0 = INT_MAX;
        --i;
        ++newadd;
        while (i >= 0 && k >= j) {
            while (k >= j && arr[k] >= arr[i]) {
                --newadd;
                --k;
            }
            if (newadd < 0)
                ans0 = min(ans0, add + newadd);
            --i;
            ++newadd;
        }
        ans += ans0;
        ans = min(ans, j);
        ans = min(ans, n - 1 - i0);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{1, 2, 3, 10, 4, 2, 3, 5};
    Solution().findLengthOfShortestSubarray(v);
    return 0;
}
