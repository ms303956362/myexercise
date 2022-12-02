#include "usual.h"

class Solution {
public:
    bool digitCount(string num) {
        int n = num.size();
        vector<int> cnt(10);
        for (const auto& c : num) {
            ++cnt[c - '0'];
        }
        for (int i = 0; i < n; ++i) {
            if (cnt[i] != num[i] - '0') {
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
