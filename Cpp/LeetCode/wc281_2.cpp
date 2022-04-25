#include "usual.h"

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *p = head;
        vector<int> a;
        while (p) {
            if (p->val) {
                a.back() += p->val;
            } else {
                a.push_back(0);
            }
            p = p->next;
        }
        a.pop_back();
        p = dummy;
        for (const auto& num : a) {
            p->next = new ListNode(num);
            p = p->next;
        }
        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
