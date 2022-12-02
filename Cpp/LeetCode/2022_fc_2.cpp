#include "usual.h"

class Solution {
public:
    int transportationHub(vector<vector<int>>& path) {
        set<vector<int>> st(path.begin(), path.end());
        vector<int> in(1005), out(1005);
        set<int> t;
        for (const auto& p : path) {
            ++in[p[1]];
            ++out[p[0]];
            t.insert(p[0]);
            t.insert(p[1]);
        }
        int n = t.size();
        for (int i = 0; i <= 1000; ++i) {
            if (in[i] == n - 1 && out[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
