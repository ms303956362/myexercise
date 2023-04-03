#include "usual.h"

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        long long num = 0;
        for (const auto& c : word) {
            num = (num * 10 + c - '0') % m;
            if (num == 0) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
