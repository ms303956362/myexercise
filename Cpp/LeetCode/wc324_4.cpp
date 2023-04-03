#include "usual.h"

class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for (const auto& q : queries) {
            int i = q[0], j = q[1];
            vector<int> d1, d2;
            while (i > 0) {
                d1.push_back(i & 1);
                i >>= 1;
            }
            while (j > 0) {
                d2.push_back(j & 1);
                j >>= 1;
            }
            reverse(d1.begin(), d1.end());
            reverse(d2.begin(), d2.end());
            int k = 0;
            while (k < min(d1.size(), d2.size()) && d1[k] == d2[k]) {
                ++k;
            }
            ans.push_back(d1.size() - k + d2.size() - k + 1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
