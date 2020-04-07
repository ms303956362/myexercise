#include "usual.h"

class Solution {
public:
    int countLargestGroup(int n) {
        int sum = 0, tmp;
        vector<int> cnt(50, 0);
        for (int i = 1; i <= n; ++i) {
            sum = 0;
            tmp = i;
            while (tmp > 0) {
                sum += tmp % 10;
                tmp /= 10;
            }
            ++cnt[sum];
        }
        sort(cnt.begin(), cnt.end(), [](int i1, int i2) { return i1 > i2; });
        int cnt_max = 1;
        int max_num = cnt[0];
        for (int i = 1; i < cnt.size(); ++i) {
            if (max_num == cnt[i])
                ++cnt_max;
            else
                break;
        }
        return cnt_max;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().countLargestGroup(10000) << endl;
    return 0;
}
