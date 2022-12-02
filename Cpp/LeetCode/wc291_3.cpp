#include "usual.h"

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> st;
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            string code;
            int cnt = 0;
            for (int j = i; j < n && cnt <= k; ++j) {
                code += to_string(nums[j]);
                if (nums[j] % p == 0) {
                    ++cnt;
                }
                if (cnt <= k) {
                    if (!st.count(code)) {
                        ++ans;
                        st.insert(code);
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
