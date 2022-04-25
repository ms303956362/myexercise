#include "usual.h"

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        if (beans.size() == 1) {
            return 0;
        }
        sort(beans.begin(), beans.end());
        long long ans = 0x3f3f3f3f3f3f3f3f, sum = 0, pre = 0;
        long long n = beans.size();
        for (const auto& num : beans) {
            sum += num;
        }
        long long last = 0;
        for (long long i = 0; i < n; ++i) {
            sum -= (n - i) * (beans[i] - last);
            ans = min(ans, sum + pre);
            last = beans[i];
            pre += beans[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
