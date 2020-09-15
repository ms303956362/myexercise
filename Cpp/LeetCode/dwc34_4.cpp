#include "usual.h"

typedef long long LL;

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        if (abs(locations[start] - locations[finish]) > fuel)
            return 0;
        int n = locations.size();
        vector<pair<int, int>> tmp;
        LL MOD = 1e9 + 7;
        for (int i = 0; i != n; ++i) {
            tmp.push_back({locations[i], i});
        }
        sort(tmp.begin(), tmp.end());
        sort(locations.begin(), locations.end());
        int is, ie;
        for (int i = 0; i != n; ++i) {
            if (tmp[i].second == start)
                is = i;
            if (tmp[i].second == finish)
                ie = i;
        }
        LL ans = power_mod(2, abs(ie - is), MOD);
        int il = min(is, ie) - 1, ih = max(is, ie) + 1;
        while (il >= 0 || ih < n) {
            if (il >= 0 && abs(locations[il] - locations[is]) + abs(locations[il] - locations[ie]) <= fuel ) {
                int add = power_mod(2, abs(il - is), MOD);
                add = (add + power_mod(2, abs(il - ie), MOD)) % MOD;
                ans = (ans + add) % MOD;
            }
            if (ih < n &&  abs(locations[ih] - locations[is]) + abs(locations[ih] - locations[ie]) <= fuel ) {
                int add = power_mod(2, abs(ih - is), MOD);
                add = (add + power_mod(2, abs(ih - ie), MOD)) % MOD;
                ans = (ans + add) % MOD;
            }
            --il;
            ++ih;
        }
        return ans;
    }

    LL power_mod(LL a,LL b,LL p){
        LL ans=1;
        a%=p;
        while(b){
            if(b&1) ans=(ans*a)%p;
            a=(a*a)%p;
            b>>=1;
        }
        return ans%p;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{2, 3, 6, 8, 4};
    Solution().countRoutes(v, 1, 3, 5);
    return 0;
}
