#include "usual.h"

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> q;
        for (const auto& num : nums) {
            q.push(num);
        }
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            auto num = q.top();
            q.pop();
            ans += num;
            q.push((num + 2) / 3);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
