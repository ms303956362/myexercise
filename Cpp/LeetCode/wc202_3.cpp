#include "usual.h"

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        priority_queue<int, vector<int>, greater<int>> q;
        sort(position.begin(), position.end());
        if (m == 2)
            return *position.rbegin() - *position.begin();
        for (int i = 1; i != position.size(); ++i) {
            q.push(position[i] - position[i - 1]);
        }
        int a, b;
        while (q.size() > m - 1) {
            a = q.top();
            q.pop();
            b = q.top();
            q.pop();
            q.push(a + b);
        }
        return q.top();
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
