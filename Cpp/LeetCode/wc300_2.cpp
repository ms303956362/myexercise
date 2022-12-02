#include "usual.h"

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, d = 0;
        while (head) {
            ans[x][y] = head->val;
            auto [dx, dy] = dirs[d];
            int u = x + dx, v = y + dy;
            while (head->next && !(0 <= u && u < m && 0 <= v && v < n && ans[u][v] == -1)) {
                d = (d + 1) % 4;
                auto [dx, dy] = dirs[d];
                u = x + dx, v = y + dy;
            }
            x = u;
            y = v;
            head = head->next;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int m = 10, n = 1;
    vector<int> v{8,24,5,21,10,11,11,12,6,17};
    ListNode *dummy = new ListNode(-1), *p = dummy;
    for (const auto& a : v) {
        p->next = new ListNode(a);
        p = p->next;
    }
    Solution().spiralMatrix(m, n, dummy->next);
    return 0;
}
