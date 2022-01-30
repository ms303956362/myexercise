#include "usual.h"

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        using ll = long long;
        int m = batteries.size();
        sort(batteries.begin(), batteries.end());
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for (int cnt = 0; cnt < n; ++cnt) {
            q.push(batteries.back());
            batteries.pop_back();
        }
        ll ans = 0, last_num = 0;
        while (!batteries.empty()) {
            ll num = q.top();
            ans += num - last_num;
            q.pop();
            last_num = num;
            q.push(batteries.back() + num);
            batteries.pop_back();
        }
        ans += q.top();
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
