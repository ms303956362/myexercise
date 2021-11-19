#include "usual.h"

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (const auto& op : operations) {
            if (op == "++X" || op == "X++")
                ++x;
            else
                --x;
        }
        return x;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
