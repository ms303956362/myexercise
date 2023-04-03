#include "usual.h"

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mp;
        for (const auto& v : nums1) {
            mp[v[0]] += v[1];
        }
        for (const auto& v : nums2) {
            mp[v[0]] += v[1];
        }
        vector<vector<int>> ans;
        for (const auto& [id, c] : mp) {
            ans.push_back({id, c});
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
