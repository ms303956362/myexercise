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
    ListNode* deleteMiddle(ListNode* head) {
        vector<int> nums;
        auto p = head;
        while (p) {
            nums.push_back(p->val);
            p = p->next;
        }
        int n = nums.size();
        ListNode *dummy = new ListNode(-1);
        p = dummy;
        for (int i = 0; i < n; ++i) {
            if (i == n / 2)
                continue;
            p->next = new ListNode(nums[i]);
            p = p->next;
        }
        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
