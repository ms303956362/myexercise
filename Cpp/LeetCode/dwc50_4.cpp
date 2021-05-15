#include "usual.h"

class Solution {
public:
    int makeStringSorted(string s) {
        int n = s.size();
        long long MOD = 1e9 + 7;
        vector<long long> fact(3001, 1);
        for (long long i = 1; i <= 3000; ++i) {
            fact[i] = (i * (fact[i - 1] % MOD)) % MOD;
        }
        vector<long long> invfact(3001, 1);
        for (long long i = 1; i <= 3000; ++i) {
            invfact[i] = pow_mod(fact[i], MOD - 2, MOD);
        }
        int i = 1;
        vector<int> cnt(128);
        bool ok = false;
        for (i = n - 1; i >= 1; --i) {
            ++cnt[s[i]];
            if (s[i] < s[i - 1]) {
                ok = true;
                break;
            }
        }
        long long ans = 0;
        while (ok && i >= 1) {
            int j = prev(lower_bound(s.begin() + i, s.end(), s[i - 1])) - s.begin();
            int tmp = s[j];
            s[j] = s[i - 1];
            s[i - 1] = tmp;
            ++cnt[s[j]];
            --cnt[s[i - 1]];
            long long addnum = fact[n - i];
            for (int k = 'a'; k <= 'z'; ++k) {
                if (cnt[k] > 1)
                    addnum = (addnum * invfact[cnt[k]]) % MOD;
            }
            ans = (ans + addnum) % MOD;
            while (i >= 1 && s[i] >= s[i - 1])
                --i;
        }
        return ans;
    }
    
    long long pow_mod(long long a,long long b,long long  c) {
        long long ans = 1,base=a;// ans：结果；base：底数
        base = base % c;
        if(b==0)
        {
            return 1%c;// 任意a的0次幂都是1,故直接用1%c即可 
        } 
        while(b)
        {   
            if(b & 1) // 与运算，判断奇偶性
            ans = (ans*base) % c; 
            b = b >> 1;// 右移一位，相当于除2
            base = (base * base) % c; 
        } 
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
