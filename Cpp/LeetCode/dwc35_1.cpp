#include "usual.h"

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        for (int i = 1; i <= arr.size(); i += 2) {
            for (int j = 0; j <= arr.size() - i; ++j) {
                for (int k = 0; k != i; ++k) {
                    ans += arr[j + k];
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
