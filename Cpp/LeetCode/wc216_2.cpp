#include "usual.h"

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        int num = 0;
        for (int i = 0; i != n; ++i) {
            num = max(k - (n - i - 1) * 26, 1);
            ans[i] += num - 1;
            k -= num;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
