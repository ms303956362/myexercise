#include "usual.h"

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v1, v2, v3;
        for (const auto& num : nums) {
            if (num < pivot) {
                v1.push_back(num);
            } else if (num == pivot) {
                v3.push_back(num);
            } else {
                v2.push_back(num);
            }
        }
        vector<int> ans;
        for (const auto& num : v1) {
            ans.push_back(num);
        }
        for (const auto& num : v3) {
            ans.push_back(num);
        }
        for (const auto& num : v2) {
            ans.push_back(num);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
