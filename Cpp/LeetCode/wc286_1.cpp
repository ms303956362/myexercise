#include "usual.h"

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_set<int> s1, s2;
        for (int i = 0; i < n1; ++i) {
            bool ok = true;
            for (int j = 0; j < n2;++j) {
                if (nums1[i] == nums2[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                s1.insert(nums1[i]);
            }
        }
        for (int j = 0; j < n2; ++j) {
            bool ok = true;
            for (int i = 0; i < n1;++i) {
                if (nums1[i] == nums2[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                s2.insert(nums2[j]);
            }
        }
        vector<vector<int>> ans;
        ans.push_back(vector<int>(s1.begin(), s1.end()));
        ans.push_back(vector<int>(s2.begin(), s2.end()));
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
