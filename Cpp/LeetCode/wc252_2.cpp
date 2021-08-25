#include "usual.h"

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long ans = 0;
        int n = milestones.size();
        priority_queue<int> q(milestones.begin(), milestones.end());
        while (q.size() > 1) {
            int n1 = q.top();
            q.pop();
            int n2 = q.top();
            q.pop();
            ans += 2 * n2;
            if (n1 > n2)
                q.push(n1 - n2);
        }
        if (!q.empty())
            ++ans;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
