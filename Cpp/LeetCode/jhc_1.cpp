#include "usual.h"

/**
 * Definition for singly-linked list.*/
struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteListNode(ListNode* head) {
        ListNode* p = head;
        while (p->next) {
            p->next = p->next->next;
            p = p->next;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
