#include "usual.h"

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0, n = word.size();
        for (const auto& p : patterns) {
            int m = p.size();
            if (m > n)
                continue;
            for (int i = 0; i <= n - m; ++i) {
                if (word.substr(i, m) == p) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
