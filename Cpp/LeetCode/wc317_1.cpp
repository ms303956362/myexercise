#include "usual.h"

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, cnt = 0;
        for (const auto& num : nums) {
            if (num % 3 == 0 && num % 2 == 0) {
                sum += num;
                ++cnt;
            }
        }
        return cnt == 0 ? 0 : (sum / cnt);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
