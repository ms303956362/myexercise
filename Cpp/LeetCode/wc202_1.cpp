#include "usual.h"

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool f1 = false, f2 = false;
        for (int i : arr) {
            if (i % 2 == 1 && f1 && f2)
                return true;
            f1 = f2;
            f2 = ((i % 2) == 1);
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
