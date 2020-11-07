#include "usual.h"

class Solution {
public:
    double trimMean(vector<int>& arr) {
        double sum = 0;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = n / 20; i != n - n / 20; ++i) {
            sum += (double)arr[i];
        }
        return sum / (0.9 * n);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
