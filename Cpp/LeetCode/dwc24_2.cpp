#include "usual.h"

class Solution {
private:
    vector<int> fibs;

public:
    int findMinFibonacciNumbers(int k) {
        int n1 = 1, n2 = 1, tmp;
        fibs.push_back(1);
        while (n2 <= k) {
            tmp = n2;
            n2 = n1 + n2;
            n1 = tmp;
            fibs.push_back(n1);
        }
        int cnt = 0;
        for (int i = fibs.size() - 1; i >= 0 && k > 0; --i) {
            if (k >= fibs[i]) {
                ++cnt;
                k -= fibs[i];
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().findMinFibonacciNumbers(1e9) << endl;
    return 0;
}
