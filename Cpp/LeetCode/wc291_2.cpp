#include "usual.h"

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> last_index;
        int n = cards.size(), ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (last_index.count(cards[i])) {
                ans = min(ans, i - last_index[cards[i]] + 1);
            }
            last_index[cards[i]] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
