#include "usual.h"

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size(), ans = 0;
        for (int i = 0; i <= n - k; ++i) {
            int sub = stoi(s.substr(i, k));
            if (sub != 0 && num % sub == 0) {
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
