#include "usual.h"

class Solution {
public:
    int numberEvenListNode(ListNode* head) {
        auto p = head;
        int ans = 0;
        while (p) {
            if (p->val % 2 == 1) {
                ++ans;
            }
            p = p->next;
        }
        return ans;
    }
};