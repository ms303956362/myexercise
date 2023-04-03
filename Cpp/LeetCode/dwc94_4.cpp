#include "usual.h"

#define ll long long  
int const MOD = 1e9 + 7;  
int const MAX = 100000;  
ll fac[MAX + 5], inv_fac[MAX + 5];  
int n, m;  
 //预处理阶乘
ll qpow(ll x, ll n)  
{  
    ll res = 1;  
    while(n)  
    {  
        if(n & 1)  
            res = (res * x) % MOD;  
        x = (x * x) % MOD;  
        n >>= 1;  
    }  
    return res;  
}  
//阶乘逆元 
void pre()  
{  
    fac[0] = 1;  
    for(int i = 1; i <= MAX; i++)  
        fac[i] = (fac[i - 1] * i) % MOD;  
    inv_fac[MAX] = qpow(fac[MAX], MOD - 2);  
    for(int i = MAX - 1; i >= 0; i--)  
        inv_fac[i] = (inv_fac[i + 1] * (i + 1)) % MOD;   
} 

bool is_init = false;

class Solution {
public:
    int countAnagrams(string s) {
        if (!is_init) {
            pre();
            is_init = true;
        }
        vector<string> words;
        auto split = [](const string& s, vector<string>& words) {
            int i = 0, n = s.size();
            while (i < n) {
                int j = i + 1;
                while (j < n && s[j] != ' ') {
                    ++j;
                }
                words.push_back(s.substr(i, j - i));
                i = j;
            }
        };
        split(s, words);
        long long ans = 1;
        for (const auto& w : words) {
            cout << w << endl;
            vector<int> cnt(26);
            for (const auto& c : w) {
                ++cnt[c - 'a'];
            }
            int l = w.size();
            ans = (ans * fac[l]) % MOD;
            for (int i = 0; i < 26; ++i) {
                ans = (ans * inv_fac[cnt[i]]) % MOD;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
