#include "usual.h"

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1(nums1.begin(), nums1.end()), st2(nums2.begin(), nums2.end());
        for (int i = 1; i <= 9; ++i) {
            if (st1.count(i) && st2.count(i)) {
                return i;
            }
        }
        for (int i = 10; i <= 99; ++i) {
            int x = i % 10, y = i / 10;
            if (st1.count(x) && st2.count(y) || st1.count(y) && st2.count(x)) {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
