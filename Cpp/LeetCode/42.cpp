#include "usual.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> r(n, -1), s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && height[s.back()] < height[i]) {
                r[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }
        while (!s.empty())
            s.pop_back();
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            cout << r[i] << " ";
            while (!s.empty() && height[s.back()] <= height[i]) {
                if (r[s.back()] != -1) {
                    ans += (min(height[r[s.back()]], height[i]) - height[s.back()]) * (r[s.back()] - i - 1);
                }
                s.pop_back();
            }
            s.push_back(i);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{0,1,0,2,1,0,1,3,2,1,2,1};
    Solution().trap(v);
    return 0;
}
