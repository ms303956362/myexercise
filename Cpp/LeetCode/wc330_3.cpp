#include "usual.h"

using ll = long long;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        ll n = weights.size();
        vector<ll> a;
        for (int i = 0; i < n - 1; ++i) {
            a.push_back(weights[i] + weights[i + 1]);
        }
        sort(a.begin(), a.end());
        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i < k - 1; ++i) {
            sum1 += a[i];
        }
        reverse(a.begin(), a.end());
        for (int i = 0; i < k - 1; ++i) {
            sum2 += a[i];
        }
        return sum2 - sum1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
