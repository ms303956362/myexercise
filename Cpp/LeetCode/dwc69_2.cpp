#include "usual.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        for (auto p = head; p; p = p->next) {
            v.push_back(p->val);
        }
        int n = v.size();
        int ans = INT_MIN;
        for (int i = 0; i < n / 2; ++i) {
            ans = max(ans, v[i] + v[n - i - 1]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
