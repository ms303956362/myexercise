#include "usual.h"

using ll = long long;

ll pow(ll x, ll n, ll mod) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = (ret * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

int s[100005];

int breakdown(int N) {
    unordered_set<int> result;
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {  // 如果 i 能够整除 N，说明 i 为 N 的一个质因子。
        while (N % i == 0) N /= i;
        result.insert(i);
        }
    }
    if (N != 1) {  // 说明再经过操作之后 N 留下了一个素数
        result.insert(N);
    }
    return result.size();
}

class Solution {
    bool is_init = false;
public:
    int maximumScore(vector<int>& nums, int k) {
        if (!is_init) {
            for (int i = 1; i < 100005; ++i) {
                s[i] = breakdown(i);
            }
            is_init = true;
        }
        int n = nums.size();
        vector<int> score(n);
        for (int i = 0; i < n; ++i) {
            score[i] = s[nums[i]];
        }
        vector<int> l(n, -1), r(n, n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && score[i] > score[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                l[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && score[i] >= score[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                r[i] = st.top();
            }
            st.push(i);
        }
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            q.emplace(nums[i], i);
        }
        ll ans = 1, mod = 1e9 + 7;
        while (!q.empty() && k > 0) {
            auto [x, i] = q.top();
            q.pop();
            ll p = min((ll)k, (ll)(i - l[i]) * (ll)(r[i] - i));
            ans = (ans * pow(x, p, mod)) % mod;
            k -= p;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{1};
    int k = 1;
    cout << Solution().maximumScore(a, k) << endl;
    return 0;
}
