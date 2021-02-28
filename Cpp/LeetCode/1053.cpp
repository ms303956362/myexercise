#include "usual.h"

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] > arr[i + 1]) {
                cout << i << endl;
                int j = lower_bound(arr.begin() + i + 1, arr.end(), arr[i]) - arr.begin() - 1;
                cout << j << " " << arr[j] << endl;
                j = lower_bound(arr.begin() + i + 1, arr.end(), arr[j]) - arr.begin();
                swap(arr[i], arr[j]);
                break;
            }
        }
        return arr;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> a{3, 1, 1, 3};
    Solution().prevPermOpt1(a);
    return 0;
}
