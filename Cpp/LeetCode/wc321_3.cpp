#include "usual.h"

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> a;
        while (head) {
            a.push_back(head->val);
            head = head->next;
        }
        int mx = 0, n = a.size();
        vector<bool> r(n, true);
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] < mx) {
                r[i] = false;
            }
            mx = max(mx, a[i]);
        }
        ListNode *dummy = new ListNode(-1), *p = dummy;
        for (int i = 0; i < n; ++i) {
            if (r[i]) {
                p->next = new ListNode(a[i]);
                p = p->next;
            }
        }
        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
