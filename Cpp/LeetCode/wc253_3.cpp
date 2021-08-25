#include "usual.h"

class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0, max_cnt = 0;
        for (const auto& c : s) {
            cnt += (c == ']' ? 1 : -1);
            max_cnt = max(max_cnt, cnt);
        }
        return (max_cnt + 1) / 2;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
