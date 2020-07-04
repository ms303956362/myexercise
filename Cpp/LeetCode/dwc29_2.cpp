#include "usual.h"

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> f;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0)
                f.push_back(i);
        }
        if (f.size() < k)
            return -1;
        else
            return f[k - 1];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
