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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        auto p = head;
        vector<int> a;
        while (p) {
            a.push_back(p->val);
            p = p->next;
        }
        int l = 1, n = a.size();
        for (int i = 0; i < n; i += l, ++l) {
            int beg = i, end = min(i + l, n);
            if ((end - beg) % 2 != 0)
                continue;
            reverse(a.begin() + beg, a.begin() + end);
        }
        ListNode *dummy = new ListNode();
        p = dummy;
        for (int i = 0; i < n; ++i, p = p->next)
            p->next = new ListNode(a[i]);
        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
