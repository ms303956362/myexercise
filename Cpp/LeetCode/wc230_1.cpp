#include "usual.h"

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int key = 0;
        if (ruleKey == "color")
            key = 1;
        else if (ruleKey == "name")
            key = 2;
        int ans = 0;
        for (const auto& it : items) {
            if (it[key] == ruleValue)
                ++ans;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
