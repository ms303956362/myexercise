#include "usual.h"

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        vector<unordered_map<int, int>> cnt(maxValue + 1);
        vector<int> cnt0(n + 1);
        int mod = 1e9 + 7;
        for (int i = maxValue; i >= 1; --i) {
            cnt[i][1] = 1;
            for (int j = 2; i * j <= maxValue; ++j) {
                for (const auto& [l, c] : cnt[i * j]) {
                    if (l == n) {
                        continue;
                    }
                    cnt[i][l + 1] = (cnt[i][l + 1] + c) % mod;
                }
            }
            for (const auto& [l, c] : cnt[i]) {
                cnt0[l] += c;
            }
        }
        vector<vector<long long>> C;
        C.resize(n + 1, vector<long long>(20));
        C[0][0] = C[1][0] = C[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i && j <= 16; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }

    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
