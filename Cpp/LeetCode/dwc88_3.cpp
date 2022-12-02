#include "usual.h"

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int s1 = 0, s2 = 0;
        for (const auto& num : nums1) {
            s1 ^= num;
        }
        for (const auto& num : nums2) {
            s2 ^= num;
        }
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 % 2 == 0) {
            s2 = 0;
        }
        if (n2 % 2 == 0) {
            s1 = 0;
        }
        return s1 ^ s2;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
