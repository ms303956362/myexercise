#include "usual.h"

int solution(vector<int> &X, vector<int> &Y) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int n = X.size();
    map<double, long long > cnt;
    cnt[0] = 1;
    long long mod = 1e9 + 7;
    for (int i = 0; i < n; ++i) {
        double num = 1.0 * X[i] / Y[i];
        if (num <= 1.0 + 1e-12) {
            map<double, long long> cnt0 = cnt;
            for (const auto& p : cnt) {
                double sum = p.first;
                long long c = p.second;
                if (sum + num <= 1.0 + 1e-12) {
                    cnt0[sum + num] = (cnt0[sum + num] + c) % mod;
                }
            }
            cnt = cnt0;
        }
    }
    return cnt[1.0];
}

map<double, int> dp[100005];
double nums[100005];
void dfs(int i, int n, double sum) {
    if (dp[i].count(sum)) {
        return;
    }
    if (abs(sum) < 1e-14) {
        dp[i][sum] = 1;
        return;
    }
    dp[i][sum] = 0;
    if (i == n) {
        return;
    }
    if (sum < 0) {
        return;
    }
    int mod = 1e9 + 7;
    dfs(i + 1, n, sum);
    dp[i][sum] = (dp[i][sum] + dp[i + 1][sum]) % mod;
    dfs(i + 1, n, sum - nums[i]);
    dp[i][sum] = (dp[i][sum] + dp[i + 1][sum - nums[i]]) % mod;
}

int solution2(vector<int> &X, vector<int> &Y) {
    int n = X.size();
    for (int i = 0; i < n; ++i) {
        dp[i].clear();
        nums[i] = 1.0 * X[i] / Y[i];
    }
    dp[n][0] = 1;
    dfs(0, n, 1.0);
    return dp[0][1.0];
}

int main(int argc, char const *argv[])
{
    vector<int> X1{1, 1, 2};
    vector<int> Y1{3, 2, 3};
    cout << solution2(X1, Y1) << endl;
    vector<int> X2{1, 1, 1};
    vector<int> Y2{2, 2, 2};
    cout << solution2(X2, Y2) << endl;
    vector<int> X3{1, 2, 3, 1, 2, 12, 8, 4};
    vector<int> Y3{5, 10, 15, 2, 4, 15, 10, 5};
    cout << solution2(X3, Y3) << endl;
    return 0;
}
