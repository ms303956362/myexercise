#include "usual.h"

class Solution {
public:
    bool isFascinating(int n) {
        int n2 = 2 * n, n3 = 3 * n;
        string s = to_string(n) + to_string(n2) + to_string(n3);
        vector<int> cnt(10);
        for (const auto& c : s) {
            ++cnt[c - '0'];
        }
        if (cnt[0] != 0) {
            return false;
        }
        for (int i = 1; i < 10; ++i) {
            if (cnt[i] != 1) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
