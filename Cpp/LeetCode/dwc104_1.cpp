#include "usual.h"

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (const auto& s : details) {
            if (stoi(s.substr(11, 2)) > 60) {
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
