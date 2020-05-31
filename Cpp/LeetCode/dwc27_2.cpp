#include "usual.h"

class Solution {
public:
    bool hasAllCodes(string ss, int k) {
        if (ss.size() <= k)
            return false;
        unordered_set<int> s;
        int num = 0;
        for (int i = 0; i != k; ++i) {
            num = num << 1;
            num |= ss[i] - '0';
        }
        s.insert(num);
        int mask = (1 << k) - 1;
        for (int i = k; i != ss.size(); ++i){
            num = (num << 1) & mask;
            num |= ss[i] - '0';
            s.insert(num);
        }
        if (s.size() == mask + 1)
            return true;
        else
            return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution().hasAllCodes("00110110", 2);
    return 0;
}
