#include "usual.h"

class Solution {
public:
    int lastMaterial(vector<int>& material) {
        priority_queue<int> q;
        for (const auto& m : material) {
            q.push(m);
        }
        while (q.size() > 1) {
            int m1 = q.top();
            q.pop();
            int m2 = q.top();
            q.pop();
            if (m1 != m2) {
                q.push(abs(m1 - m2));
            }
        }
        return q.empty() ? 0 : q.top();
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
