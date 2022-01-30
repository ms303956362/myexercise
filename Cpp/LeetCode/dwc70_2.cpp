#include "usual.h"

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long min_num = 0, max_num = 0, curr = 0;
        for (const auto& d : differences) {
            curr += d;
            min_num = min(min_num, curr);
            max_num = max(max_num, curr);
        }
        long long ans = (upper - lower) - (max_num - min_num) + 1;
        if (ans < 0)
            return 0;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
