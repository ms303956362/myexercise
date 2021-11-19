#include "usual.h"

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> cnt1, cnt2, cnt3, cnt;
        for (const auto& num : nums1) {
            cnt1.insert(num);
            cnt.insert(num);
        }
        for (const auto& num : nums2) {
            cnt2.insert(num);
            cnt.insert(num);
        }
        for (const auto& num : nums3) {
            cnt3.insert(num);
            cnt.insert(num);
        }
        vector<int> ans;
        for (const auto& num : cnt) {
            if (cnt1.count(num) && cnt2.count(num) || cnt1.count(num) && cnt3.count(num) || cnt3.count(num) && cnt2.count(num))
                ans.push_back(num);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
