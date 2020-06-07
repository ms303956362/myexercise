#include "usual.h"

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> res(k, 0);
        int n = arr.size();
        int mid = arr[(n - 1) / 2];
        for (int l = 0, r = n - 1, i = 0; i != k; ++i) {
            if ((mid - arr[l]) > (arr[r] - mid)) {
                res[i] = arr[l];
                ++l;
            } else if ((mid - arr[l]) <= (arr[r] - mid)) {
                res[i] = arr[r];
                --r;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
