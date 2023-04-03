#include "usual.h"

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        priority_queue<int> q;
        for (int i = 0; i < n; ++i) {
            q.push(reward1[i] - reward2[i]);
        }
        int ans = 0;
        for (const auto& r : reward2) {
            ans += r;
        }
        for (int i = 0; i < k; ++i) {
            auto d = q.top();
            q.pop();
            ans += d;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
