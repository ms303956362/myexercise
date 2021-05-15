#include "usual.h"

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int n = height.size();
        vector<int> rightmax(n, -1);
        for (int i = 1; i != n; ++i) {
            while (!s.empty() && height[i] > height[s.top()]) {
                rightmax[s.top()] = height[i];
                s.pop();
            }
            s.push(i);
        }
        int ans = 0;
        while (!s.empty())
            s.pop();
        for (int i = n - 2; i >= 0; --i) {
            while (!s.empty() && height[i] > height[s.top()]) {
                if (rightmax[s.top()] != -1)
                    ans += min(height[i], rightmax[s.top()]) - height[s.top()];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution().trap(v);
    return 0;
}
