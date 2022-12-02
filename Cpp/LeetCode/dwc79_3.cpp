#include "usual.h"

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> d(n);
        for (const auto& r : roads) {
            ++d[r[0] - 1];
            ++d[r[1] - 1];
        }
        sort(d.begin(), d.end());
        long long ans = 0;
        for (long long i = 0; i < n; ++i) {
            ans += (i + 1) * d[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
