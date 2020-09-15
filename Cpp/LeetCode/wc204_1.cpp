#include "usual.h"

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if (n < m * k)
            return false;
        for (int i = 0; i <= n - m * k; ++i) {
            int j;
            for (j = 1; j < k; ++j) {
                int t;
                for (t = 0; t < m; ++t) 
                    if (arr[i + t] != arr[i + j * m + t])
                        break;
                if (t != m)
                    break;
            }
            if (j == k)
                return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
