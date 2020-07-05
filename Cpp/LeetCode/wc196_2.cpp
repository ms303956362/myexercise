#include "usual.h"

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = INT_MIN;
        for (auto i : left) {
            res = max(res, i);
        }
        for (auto i : right) {
            res = max(res, n - i);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
