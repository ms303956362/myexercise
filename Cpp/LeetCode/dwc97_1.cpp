#include "usual.h"

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (auto num : nums) {
            vector<int> v;
            while (num > 0) {
                v.push_back(num % 10);
                num /= 10;
            }
            reverse(v.begin(), v.end());
            for (const auto& d : v) {
                ans.push_back(d);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
