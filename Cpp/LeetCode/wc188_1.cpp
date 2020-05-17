#include "usual.h"

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        for (int i = 1, j = 0; i <= n; ++i) {
            if (target[j] == i) {
                res.push_back("Push");
                ++j;
                if (j == target.size())
                    break;
            } else {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    
    return 0;
}
