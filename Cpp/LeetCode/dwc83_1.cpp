#include "usual.h"

/*
"Flush"：同花，五张相同花色的扑克牌。
"Three of a Kind"：三条，有 3 张大小相同的扑克牌。
"Pair"：对子，两张大小一样的扑克牌。
"High Card"：高牌，五张大小互不相同的扑克牌。
*/

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int n = ranks.size();
        bool is_1 = true;
        for (int i = 1; i < n; ++i) {
            if (suits[i] != suits[0]) {
                is_1 = false;
                break;
            }
        }
        if (is_1) {
            return "Flush";
        }
        sort(ranks.begin(), ranks.end());
        for (int i = 2; i < n; ++i) {
            if (ranks[i] == ranks[i - 1] && ranks[i] == ranks[i - 2]) {
                return "Three of a Kind";
            }
        }
        for (int i = 1; i < n; ++i) {
            if (ranks[i] == ranks[i - 1]) {
                return "Pair";
            }
        }
        return "High Card";
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
