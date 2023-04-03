#include "usual.h"

class Solution {
public:
    int minMaxDifference(int num) {
        long long max_num = 0, min_num = 1e8;
        string s = to_string(num);
        int n = s.size();
        for (char c1 = '0'; c1 <= '9'; ++c1) {
            for (char c2 = '0'; c2 <= '9'; ++c2) {
                string tmp = s;
                for (int i = 0; i < n; ++i) {
                    if (s[i] == c1) {
                        s[i] = c2;
                    }
                }
                long long num2 = stoll(s);
                max_num = max(max_num, num2);
                min_num = min(min_num, num2);
                s = tmp;
            }
        }
        return max_num - min_num;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
