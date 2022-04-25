#include "usual.h"

class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string tmp;
            int n = s.size();
            for (int i = 0; i < n; i += k) {
                int sum = 0;
                for (int j = i; j < min(i + k, n); ++j) {
                    sum += s[j] - '0';
                }
                tmp += to_string(sum);
            }
            s = tmp;
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
