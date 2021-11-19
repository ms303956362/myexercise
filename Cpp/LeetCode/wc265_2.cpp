#include "usual.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> nums;
        for (auto p = head; p; p = p->next) {
            nums.push_back(p->val);
        }
        int n = nums.size();
        vector<int> points;
        int min_dis = INT_MAX;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
                points.push_back(i);
            else if (nums[i - 1] > nums[i] && nums[i] < nums[i + 1])
                points.push_back(i);
            if (points.size() >= 2)
                min_dis = min(min_dis, points.back() - points[points.size() - 2]);
        }
        vector<int> ans(2, -1);
        if (min_dis != INT_MAX) {
            ans[0] = min_dis;
            ans[1] = points.back() - *points.begin();
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
