#include "usual.h"

class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0)
            return 0;
        vector<int> d;
        bool ispos = (num > 0);
        num = abs(num);
        while (num > 0) {
            d.push_back(num % 10);
            num /= 10;
        }
        if (ispos) {
            sort(d.begin(), d.end());
        } else {
            sort(d.rbegin(), d.rend());
        }
        int n = d.size(), i = 0;
        while (i < n - 1 && d[i] == 0) {
            ++i;
        }
        swap(d[i], d[0]);
        long long ans = 0;
        for (i = 0; i < n; ++i) {
            ans = ans * 10 + d[i];
        }
        return ispos ? ans : -ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
