#include "usual.h"

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param a ListNode类 
     * @param b ListNode类 
     * @return ListNode类
     */
    ListNode* xorList(ListNode* a, ListNode* b) {
        // write code here
        vector<int> va, vb;
        while (a) {
            va.push_back(a->val);
            a = a->next;
        }
        while (b) {
            vb.push_back(b->val);
            b = b->next;
        }
        reverse(va.begin(), va.end());
        vector<int> vc;
        int i = 0;
        while (i < va.size() && i < vb.size()) {
            vc.push_back(va[i] ^ vb[i]);
            ++i;
        }
        while (i < va.size()) {
            vc.push_back(va[i]);
            ++i;
        }
        while (i < vb.size()) {
            vc.push_back(vb[i]);
            ++i;
        }
        i = vc.size() - 1;
        while (i >= 0 && vc[i] == 0) {
            --i;
        }
        if (i < 0) {
            return new ListNode(0);
        }
        ListNode *dummy = new ListNode(-1), *p = dummy;
        while (i >= 0) {
            p->next = new ListNode(vc[i]);
            p = p->next;
            --i;
        }
        return dummy->next;
    }
};