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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        cout << head->val << endl;
        ListNode* p1 = head, *p2 = head;
        while (p2->next) {
            p2 = p2->next;
            if (p2->next) {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        ListNode* head2 = p1->next;
        p1->next = nullptr;
        p1 = sortList(head);
        p2 = sortList(head2);
        ListNode* dummy = new ListNode(-1), *p = dummy;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        while (p1) {
            p->next = p1;
            p1 = p1->next;
            p = p->next;
        }
        while (p2) {
            p->next = p2;
            p2 = p2->next;
            p = p->next;
        }
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

ListNode* buildList(const vector<int>& v) {
    ListNode *dummy = new ListNode(-1), *p = dummy;
    for (const auto& num : v) {
        p->next = new ListNode(num);
        p = p->next;
    }
    return dummy->next;
}

int main(int argc, char const *argv[])
{
    vector<int> v{4,2,1,3};
    Solution().sortList(buildList(v));
    return 0;
}
