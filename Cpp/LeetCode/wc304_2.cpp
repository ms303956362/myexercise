#include "usual.h"

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size(), ans = 1;
        while (ans * (1 + ans) / 2 <= n) {
            ++ans;
        }
        return ans - 1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
