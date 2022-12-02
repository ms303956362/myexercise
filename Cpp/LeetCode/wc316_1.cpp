#include "usual.h"

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        auto str2int = [](const string& s) {
            return stoi(s.substr(0, 2)) * 24 + stoi(s.substr(3, 2));
        };
        int s1 = str2int(event1[0]), e1 = str2int(event1[1]);
        int s2 = str2int(event2[0]), e2 = str2int(event2[1]);
        return min(e1, e2) >= max(s1, s2);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
