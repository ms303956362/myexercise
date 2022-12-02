#include "usual.h"

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n = rolls.size(), i = n - 1;
        int ans = 1;
        while (i >= 0) {
            unordered_set<int> s;
            for (int j = 1; j <= k; ++j) {
                s.insert(j);
            }
            while (i >= 0 && !s.empty()) {
                if (s.count(rolls[i])) {
                    s.erase(rolls[i]);
                }
                --i;
            }
            if (s.empty()) {
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
