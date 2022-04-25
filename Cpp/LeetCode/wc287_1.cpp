#include "usual.h"

class Solution {
public:
    int convertTime(string current, string correct) {
        int curr = stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3, 2));
        int corr = stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3, 2));
        int diff = corr - curr, ans = 0;
        vector<int> a{60, 15, 5, 1};
        for (const auto& d : a) {
            ans += diff / d;
            diff %= d;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
