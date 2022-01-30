#include "usual.h"

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for (const auto& num : nums) {
            if (num > 0) {
                pos.push_back(num);
            } else {
                neg.push_back(num);
            }
        }
        vector<int> ans;
        int n = pos.size();
        for (int i = 0; i < n; ++i) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
