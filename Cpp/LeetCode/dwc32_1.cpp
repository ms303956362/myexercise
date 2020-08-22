#include "usual.h"

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i, j = 0;
        int lost = 0;
        for (i = 1;;++i) {
            if (j == arr.size() || arr[j] != i)
                ++lost;
            else
                ++j;
            if (lost == k)
                break;
        }
        return i;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
