#include "usual.h"

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;
        for (const auto& h : hours) {
            ans += h >= target;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
