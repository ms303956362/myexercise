#include "usual.h"
class Solution {
    
public:
    int getMaxLength(int n, vector<int>& a) {
        // write code here
        if (n < 3)
            return 0;
        int res = 0, cnt = 0, s = 0;
        for (int i = 1; i != n; ++i) {
            if (s == 0 && a[i] > a[i - 1]) {
                s = 1;
                cnt = 2;
            } else if (s == 1) {
                if (a[i] == a[i - 1])
                    s = 0;
                else if (a[i] < a[i - 1]) {
                    s = 2;
                    ++cnt;
                } else
                    ++cnt;
            } else if (s == 2){
                if (a[i] == a[i - 1]) {
                    s = 0;
                    res = max(res, cnt);
                }
                else if (a[i] > a[i - 1]) {
                    ++cnt;
                    s = 1;
                    res = max(res, cnt);
                } else {
                    ++cnt;
                }
            }
        }
        if (s == 2)
            res = max(res, cnt);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int n = 9;
    vector<int> v{1,0,1,1,2,1,0,2,1};
    cout << Solution().getMaxLength(n, v) << endl;
    return 0;
}
