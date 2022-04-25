#include "usual.h"

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> q;
        double sum = 0, curr;
        for (const auto& num : nums) {
            sum += num;
            q.push(num);
        }
        curr = sum;
        int ans = 0;
        while (true) {
            double num = q.top();
            q.pop();
            curr -= num / 2;
            ++ans;
            if (curr <= sum / 2) {
                return ans;
            }
            q.push(num / 2);
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
