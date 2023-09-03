#include "usual.h"

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x = 0;
        for (const auto& num : derived) {
            x ^= num;
        }
        return x == 0;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
