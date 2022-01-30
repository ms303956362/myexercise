#include "usual.h"

class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size();
        long long p = power, m = modulo, pk_1 = 1, h = (s[n - k] - 'a' + 1) % m;
        for (int i = n - k + 1; i < n; ++i) {
            pk_1 = pk_1 * p % m;
            h = (h + (s[i] - 'a' + 1) * pk_1 % m) % m;
        }
        int index = 0;
        if (h == hashValue) {
            index = n - k;
        }
        for (int i = n - k - 1; i >= 0; --i) {
            h = (h - (s[i + k] - 'a' + 1) * pk_1 % m) * p % m;
            if (h < 0) {
                h += (-h + m) / m * m;
            }
            h = (h + (s[i] - 'a' + 1) % m) % m;
            if (h == hashValue) {
                index = i;
            }
        }
        return s.substr(index, k);
    }
};

int main(int argc, char const *argv[])
{
    string s("leetcode");
    int power = 7, modulo = 20, k = 2, hash = 0;
    Solution().subStrHash(s, power, modulo, k, hash);
    return 0;
}
