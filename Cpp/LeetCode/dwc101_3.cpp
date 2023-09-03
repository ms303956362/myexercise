#include "usual.h"

class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size(), g = __gcd(n, k);
        long long ans = 0;
        for (int i = 0; i < g; ++i) {
            vector<long long> v;
            int t = i;
            for (int j = 0; j < n / g; ++j) {
                v.push_back(arr[t]);
                t = (t + k) % n;
            }
            long long l = v.size();
            sort(v.begin(), v.end());
            vector<long long> pre(l + 1);
            for (int j = l - 1; j >= 0; --j) {
                pre[j] = pre[j + 1] + v[j];
            }
            long long sum = pre[0];
            for (long long j = 0; j < l; ++j) {
                sum = min(sum, j * v[j] - (l - j) * v[j] + pre[j] - pre[l] - (pre[0] - pre[j]));
            }
            ans += sum;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
