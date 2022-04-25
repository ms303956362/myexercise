#include "usual.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        auto p = head;
        while (p) {
            v.push_back(p->val);
            p = p->next;
        }
        int n = v.size(), i = 0, j = n - 1;
        while (i < j) {
            if (v[i] != v[j]) {
                break;
            }
            ++i;
            --j;
        }
        if (i >= j) {
            return true;
        }
        auto check = [&](int x, int y) {
            while (x < y) {
                if (v[x] != v[y]) {
                    return false;
                }
                ++x;
                --y;
            }
            return true;
        };
        return check(i + 1, j) || check(i, j - 1);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
