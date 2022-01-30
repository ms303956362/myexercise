#include "usual.h"

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.emplace(nums1[0] + nums2[0], make_pair(0, 0));
        vector<vector<bool>> vst(m, vector<bool>(n, false));
        vector<vector<int>> ans;
        vst[0][0] = true;
        int cnt = 1;
        cout << 1 << endl;
        while (!q.empty() && ans.size() < k) {
            auto [sum, p] = q.top();
            q.pop();
            auto [i, j] = p;
            cout << "(" << i << " " << j << "), ";
            ans.push_back({nums1[i], nums2[j]});
            if (cnt < k && i + 1 < m && !vst[i + 1][j]) {
                ++cnt;
                vst[i + 1][j] = true;
                q.emplace(nums1[i + 1] + nums2[j], make_pair(i + 1, j));
            }
            if (cnt < k && j + 1 < n && !vst[i][j + 1]) {
                ++cnt;
                vst[i][j + 1] = true;
                q.emplace(nums1[i] + nums2[j + 1], make_pair(i, j + 1));
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1{}
    return 0;
}
