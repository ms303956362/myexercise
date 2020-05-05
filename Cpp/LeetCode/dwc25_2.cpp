#include "usual.h"

class Solution {
public:
    int maxDiff(int num) {
        vector<int> d;
        while (num > 0) {
            d.push_back(num % 10);
            num /= 10;
        }
        int t1 = 9, s1 = 9, t2 = 0, s2 = 0;
        for (int i = d.size() - 1; i >= 0; --i) {
            if (d[i] != 9) {
                t1 = d[i];
                break;
            }
        }
        for (int i = d.size() - 1; i >= 0; --i) {
            if (i == d.size() - 1 && d[i] != 1) {
                t2 = d[i];
                s2 = 1;
                break;
            } else if (d[i] != 1 && d[i] != 0){
                t2 = d[i];
                s2 = 0;
                break;
            }
        }
        int res1 = 0, res2 = 0;
        for (int i = d.size() - 1; i >= 0; --i) {
            if (d[i] == t1)
                res1 = res1 * 10 + s1;
            else
                res1 = res1 * 10 + d[i];
            if (d[i] == t2)
                res2 = res2 * 10 + s2;
            else
                res2 = res2 * 10 + d[i];
        }
        return res1 - res2;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().maxDiff(555) << endl;
    cout << Solution().maxDiff(9) << endl;
    cout << Solution().maxDiff(123456) << endl;
    cout << Solution().maxDiff(10000) << endl;
    cout << Solution().maxDiff(9288) << endl;
    cout << Solution().maxDiff(1) << endl;
    return 0;
}
