#include "usual.h"

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<long long> v(n + 1, 0);
        v[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0')
                continue;
            long long num = 0;
            for (int j = i; j < n; ++j) {
                num = num * 10 + (s[j] - '0');
                if (num <= k) {
                    v[i] += v[j + 1];
                    v[i] %= 1000000000 + 7;
                }
                else
                    break;
            }
        }
        return v[0];
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().numberOfArrays("600342244431311113256628376226052681059918526204", 903) << endl;
    return 0;
}
