#include "usual.h"

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int maxlen = INT_MIN, cnt1 = 0;
        for (int i : nums) {
            auto [l, cnt] = count1(i);
            maxlen = max(maxlen, l);
            cnt1 += cnt;
        }
        cout << maxlen << " " << cnt1 << endl;
        return cnt1 + maxlen - 1;
    }

    pair<int, int> count1(int n) {
        int l = 0, cnt = 0;
        while (n != 0) {
            cnt += (n % 2);
            ++l;
            n /= 2;
        }
        return {l, cnt};
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
