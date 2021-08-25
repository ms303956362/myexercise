#include "usual.h"

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = 0;
        priority_queue<int> q;
        for (const auto& p : piles) {
            sum += p;
            q.push(p);
        }
        for (int i = 0; i < k; ++i) {
            int p = q.top();
            q.pop();
            sum -= p / 2;
            if (sum == 0)
                return 0;
            if (p > 0)
                q.push(p - p / 2);
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
